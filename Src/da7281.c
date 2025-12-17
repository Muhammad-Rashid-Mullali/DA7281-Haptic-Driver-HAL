#include <stdio.h>
#include <stdint.h>
#include "da7281.h"
#include "da7281_bit_defs.h"


int8_t da7281_init(da7281_handle_t *handle)
{
    uint8_t chip_rev;
    uint8_t reg;
    
    if(handle == NULL)
    {
        return DA7281_RET_NULL_ERROR;
    }

    /****************Need to check the completion of boot after 1.5ms using Suitable Timing**************/

    /*Read Chip Rev Register*/
    handle->i2c_rslt = handle->iic_read(DA7281_REG_CHIP_REV, &chip_rev, DA7281_REG_BYTE);
    if(handle->i2c_rslt == DA7281_I2C_RET_SUCCESS)
    {
        if(chip_rev != DA7281_DEFAULT_CHIP_REV)
        {
            return DA7281_RET_ERROR;
        }
    }
    
    /* Read TOP CTL1 Register*/
    if(handle->iic_read(DA7281_REG_TOP_CTL1, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_SUCCESS)
    {
        return DA7281_I2C_RET_ERROR;
    }

    /* Set Inactive Mode */
    reg &= ~(DA7281_BIT_ENABLE << OPERATION_MODE);

    /* Set Standby mode */
    reg |= (DA7281_BIT_ENABLE << STANDBY_EN);
    
    /* Update TOP CTL1 Register*/
    if(handle->iic_write(DA7281_REG_TOP_CTL1, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_SUCCESS)
    {
        return DA7281_I2C_RET_ERROR;
    }

    return DA7281_OK;
}

int8_t da7281_irq_handler(da7281_handle_t *handle)
{
    uint8_t reg;
    
    if(handle == NULL)
    {
        return DA7281_RET_NULL_ERROR;
    }

    /* Read Status Register */
    if(handle->iic_read(DA7281_REG_IRQ_STATUS1, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_SUCCESS)
    {
        return DA7281_I2C_RET_ERROR;
    }

    if(reg & (DA7281_BIT_ENABLE << STA_SEQ_CONTINUE))
    {
        /* Continuous sequence status */
        handle->receive_callback(STA_SEQ_CONTINUE);
    }

    if (reg & (DA7281_BIT_ENABLE << STA_UVLO_VBAT_OK))
    {
        /* UVLO output status */
        handle->receive_callback(STA_UVLO_VBAT_OK);
    }

    if (reg & (DA7281_BIT_ENABLE << STA_PAT_DONE))
    {
        /* Memory based sequence status  */
        handle->receive_callback(STA_PAT_DONE);
    }

    if (reg & (DA7281_BIT_ENABLE << STA_OVERTEMP_CRIT))
    {
        /* Critical chip temperature event, chip temperature has
           exceeded the critical limit of 125 °C */
           handle->receive_callback(STA_OVERTEMP_CRIT);

           /* Clear the Flag */
           uint8_t flag = NULL;
           flag |= (DA7281_BIT_ENABLE << E_OVERTEMP_CRIT);
           handle->iic_write(DA7281_REG_IRQ_EVENT1, (uint8_t*)&flag, DA7281_REG_BYTE);
    }

    
    if (reg & (DA7281_BIT_ENABLE << STA_PAT_FAULT))
    {
        /* Detected a Fault*/

        da7281_irq_sequence_t seq;

        if(handle->iic_read(DA7281_REG_IRQ_EVENT_SEQ_DIAG, (uint8_t *)&seq, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
        {
            if(seq & (DA7281_BIT_ENABLE << E_PWM_FAULT))
            {
                /* Indicates that the PWM input signal has timed out */
                handle->receive_callback(E_PWM_FAULT);

                /* Clear the Flag */
                uint8_t flag = NULL;
                flag |= (DA7281_BIT_ENABLE << E_SEQ_FAULT);
                handle->iic_write(DA7281_REG_IRQ_EVENT1, (uint8_t*)&flag, DA7281_REG_BYTE);
            }

            if(seq & (DA7281_BIT_ENABLE << E_MEM_FAULT))
            {
                /* Indicates that the Waveform Memory is corrupted
                   (empty,invalid snippet ID, invalid frame structure) */
                handle->receive_callback(E_MEM_FAULT);

                /* Clear the Flag */
                uint8_t flag = NULL;
                flag |= (DA7281_BIT_ENABLE << E_SEQ_FAULT);
                handle->iic_write(DA7281_REG_IRQ_EVENT1, (uint8_t*)&flag, DA7281_REG_BYTE);
            }

            if(seq & (DA7281_BIT_ENABLE << E_SEQ_ID_FAULT))
            {
                /*  indicating that requested sequence ID configured
                    in PS_SEQ_ID is not valid */
                handle->receive_callback(E_SEQ_ID_FAULT);

                /* Clear the Flag */
                uint8_t flag = NULL;
                flag |= (DA7281_BIT_ENABLE << E_SEQ_ID_FAULT);
                handle->iic_write(DA7281_REG_IRQ_EVENT1, (uint8_t*)&flag, DA7281_REG_BYTE);
            }
        }
    }

    if (reg & (DA7281_BIT_ENABLE << STA_WARNING))
    {
        /* Detected a Warning*/

        da7281_irq_warnings_t warning;

        if(handle->iic_read(DA7281_REG_IRQ_EVENT_WARNING_DIAG, (uint8_t *)&warning, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
        {
            if(warning & (DA7281_BIT_ENABLE << E_OVERTEMP_WARN))
            {
                /* Driver temperature has exceeded the warning limit of 105 °C!!!
                Device continues operation but limit playback or reduce drive to protect the actuator.*/
                handle->receive_callback(E_OVERTEMP_WARN);

                /* Clear the flag */
                uint8_t flag = NULL;
                flag |= (DA7281_BIT_ENABLE << E_WARNING);
                handle->iic_write(DA7281_REG_IRQ_EVENT1, (uint8_t*)&flag, DA7281_REG_BYTE);
            }

            if(warning & (DA7281_BIT_ENABLE << E_MEM_TYPE))
            {
                /* Indicates that the memory data type configured in register 
                MEM_DATA_SIGNED does not match the ACCELERATION_EN */
                da7281_top_cfg1_t accel_en;
                if(handle->iic_read(DA7281_REG_TOP_CFG1, (uint8_t *)&accel_en, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
                {
                    if(accel_en & (DA7281_BIT_ENABLE << ACCELERATION_EN) == DA7281_BOOL_TRUE)
                    {
                        /* ACCELERATION_EN = 1 So Write MEM_DATA_SIGNED = 0 */
                        accel_en = (DA7281_BIT_DISABLE << MEM_DATA_SIGNED);
                        handle->iic_write(DA7281_REG_TOP_CFG2, (uint8_t *)&accel_en, DA7281_REG_BYTE);
                    }

                    else
                    {
                        /* ACCELERATION_EN = 0 So Write MEM_DATA_SIGNED = 1 */
                        accel_en = (DA7281_BIT_ENABLE << MEM_DATA_SIGNED);
                        handle->iic_write(DA7281_REG_TOP_CFG2, (uint8_t *)&accel_en, DA7281_REG_BYTE);
                    }
                }

                /* Clear the flag */
                uint8_t flag = NULL;
                flag |= (DA7281_BIT_ENABLE << E_WARNING);
                handle->iic_write(DA7281_REG_IRQ_EVENT1, (uint8_t*)&flag, DA7281_REG_BYTE);
            }

            if(warning & (DA7281_BIT_ENABLE << E_LIM_DRIVE_ACC))
            {
                /* Indicates that acceleration is limited because the power supply
                level is lower than required for the acceleration target */
                handle->receive_callback(E_LIM_DRIVE_ACC);

                /* Clear the Flag*/
                uint8_t flag = NULL;
                flag |= (DA7281_BIT_ENABLE << E_WARNING);
                handle->iic_write(DA7281_REG_IRQ_EVENT1, (uint8_t*)&flag, DA7281_REG_BYTE);
            }

            if(warning & (DA7281_BIT_ENABLE << E_LIM_DRIVE))
            {
                /* Indicates that playback is limited because the power supply
                level is lower than the sequence targe */
                handle->receive_callback(E_LIM_DRIVE);

                /* Clear the Flag*/
                uint8_t flag = NULL;
                flag |= (DA7281_BIT_ENABLE << E_WARNING);
                handle->iic_write(DA7281_REG_IRQ_EVENT1, (uint8_t*)&flag, DA7281_REG_BYTE);
            }
        }

        else
        {
            return DA7281_I2C_RET_ERROR;
        }
    }

    if (reg & (DA7281_BIT_ENABLE << STA_ACTUATOR))
    {
        /* Detected a fault in actuator impedance,BEMF amplitude, or resonant frequency */
        handle->receive_callback(STA_ACTUATOR);

        /* Clear the Flag */
        uint8_t flag = NULL;
        flag |= (DA7281_BIT_ENABLE << E_ACTUATOR_FAULT);
        handle->iic_write(DA7281_REG_IRQ_EVENT1, &flag, DA7281_REG_BYTE);
    }

      if (reg & (DA7281_BIT_ENABLE << STA_OC))
    {
        /* Short circuit / over-current fault */
        handle->receive_callback(STA_OC);

        /* Clear the flag */
        uint8_t flag = NULL;
        flag |= (DA7281_BIT_ENABLE << E_OC_FAULT);
        handle->iic_write(DA7281_REG_IRQ_EVENT1, &flag, DA7281_REG_BYTE);
    }

    return DA7281_OK;
}

/*
*Actuator Setup Functions
*/
int8_t da7281_select_actuator_type(da7281_handle_t *handle, bool type)
{
    uint8_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    if(handle->iic_read(DA7281_REG_TOP_CFG1, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
    {
        reg &= ~(DA7281_BIT_ENABLE << ACTUATOR_TYPE);
        reg |= (type << ACTUATOR_TYPE);

        handle->iic_write(DA7281_REG_TOP_CFG1, &reg, DA7281_REG_BYTE);
    }

    else
    {
        return DA7281_RET_ERROR;
    }

    return DA7281_OK;
}

/*
*Set Actuator Nominal maximum voltage
*/
int8_t da7281_set_actuator_nommax(da7281_handle_t *handle, uint8_t value)
{
    uint8_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    if(handle->iic_read(DA7281_REG_ACTUATOR1, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
    {
        reg &= ~(DA7281_BIT_ENABLE << DA7281_REG_ACTUATOR_X_BIT_POS);
        reg |= (value << DA7281_REG_ACTUATOR_X_BIT_POS);

        handle->iic_write(DA7281_REG_ACTUATOR1, &reg, DA7281_REG_BYTE);
    }

    else
    {
        return DA7281_RET_ERROR;
    }

    return DA7281_OK;
}

/*
*Get Actuator nominal maximum voltage
*/
int8_t da7281_get_actuator_nommax(da7281_handle_t *handle, uint8_t *value)
{
    uint8_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    if(handle->iic_read(DA7281_REG_ACTUATOR1, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
    {
        *value = reg;
    }

    return DA7281_OK;
}

/*
*Set Actuator absolute maximum voltage
*/
int8_t da7281_set_actuator_absmax(da7281_handle_t *handle, uint8_t value)
{
    uint8_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    if (handle->iic_read(DA7281_REG_ACTUATOR2, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
    {
        reg &= ~(DA7281_BIT_ENABLE << DA7281_REG_ACTUATOR_X_BIT_POS);
        reg |= (value << DA7281_REG_ACTUATOR_X_BIT_POS);

        handle->iic_write(DA7281_REG_ACTUATOR2, &reg, DA7281_REG_BYTE);
    }

    else 
    {
        return DA7281_RET_ERROR;
    }

    return DA7281_OK;
}

/*
*Get Actuator absolute maximum voltage
*/
int8_t da7281_get_actuator_absmax(da7281_handle_t *handle, uint8_t *value)
{
    uint8_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    if(handle->iic_read(DA7281_REG_ACTUATOR2, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
    {
        *value = reg;
    }

    return DA7281_OK;
}

/*
*Set Actuator maximum rated current
*/
int8_t da7281_set_actuator_imax(da7281_handle_t *handle, uint8_t value)
{
    uint8_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    if (handle->iic_read(DA7281_REG_ACTUATOR3, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
    {
        reg &= ~(DA7281_BIT_ENABLE << DA7281_REG_ACTUATOR_X_BIT_POS);
        reg |= (value << DA7281_REG_ACTUATOR_X_BIT_POS);

        handle->iic_write(DA7281_REG_ACTUATOR3, &reg, DA7281_REG_BYTE);
    }

    else
    {
        return DA7281_RET_ERROR;
    }

    return DA7281_OK;
}

/*
*Get Actuator maximum rated current
*/
int8_t da7281_get_actuator_imax(da7281_handle_t *handle, uint8_t *value)
{
    uint8_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    if(handle->iic_read(DA7281_REG_ACTUATOR3, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
    {
        *value = reg;
    }

    else
    {
        return DA7281_RET_ERROR;
    }

    return DA7281_OK;
}

/*
*Set V2I_FACTOR_H
*/
int8_t da7281_set_v2i_factor_h(da7281_handle_t *handle, uint8_t value)
{
    uint8_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    if (handle->iic_read(DA7281_REG_CALIB_V2I_H, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
    {
        reg &= ~(DA7281_BIT_ENABLE << DA7281_REG_ACTUATOR_X_BIT_POS);
        reg |= (value << DA7281_REG_ACTUATOR_X_BIT_POS);

        handle->iic_write(DA7281_REG_CALIB_V2I_H, &reg, DA7281_REG_BYTE);
    }

    else
    {
        return DA7281_RET_ERROR;
    }

    return DA7281_OK;
}

/*
*Get V2I_FACTOR_H
*/
int8_t da7281_get_v2i_factor_h(da7281_handle_t *handle, uint8_t *value)
{
    uint8_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    if(handle->iic_read(DA7281_REG_CALIB_V2I_H, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
    {
        *value = reg;
    }

    else
    {
        return DA7281_RET_ERROR;
    }

    return DA7281_OK;
}

/*
*Set V2I_FACTOR_L
*/
int8_t da7281_set_v2i_factor_l(da7281_handle_t *handle, uint8_t value)
{
    uint8_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    if (handle->iic_read(DA7281_REG_CALIB_V2I_L, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
    {
        reg &= ~(DA7281_BIT_ENABLE << DA7281_REG_ACTUATOR_X_BIT_POS);
        reg |= (value << DA7281_REG_ACTUATOR_X_BIT_POS);

        handle->iic_write(DA7281_REG_CALIB_V2I_L, &reg, DA7281_REG_BYTE);
    }

    else
    {
        return DA7281_RET_ERROR;
    }

    return DA7281_OK;
}

/*
*Get V2I_FACTOR_L
*/
int8_t da7281_get_v2i_factor_l(da7281_handle_t *handle, uint8_t *value)
{
    uint8_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    if(handle->iic_read(DA7281_REG_CALIB_V2I_L, &reg, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
    {
        *value = reg;
    }

    else
    {
        return DA7281_RET_ERROR;
    }

    return DA7281_OK;
}

/*
*Get Concatenation of V2I_FACTOR
*/
int8_t da7281_get_v2i_factor(da7281_handle_t *handle, uint16_t *value)
{
    uint16_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    uint8_t *v2i_factor_h;
    if(da7281_get_v2i_factor_h(handle, v2i_factor_h) == DA7281_OK)
    {
        uint8_t *v2i_factor_l;
        if(da7281_get_v2i_factor_l(handle, v2i_factor_l) == DA7281_OK)
        {
            *value = (*v2i_factor_h * 256) + *v2i_factor_l;
        }
    }

    else
    {
        return DA7281_RET_ERROR;
    }

    return DA7281_OK;
}

/*
*Get Impedance Z from V2I_FACTOR
*/
int8_t da7281_get_impedance(da7281_handle_t *handle, uint8_t *value)
{
    uint8_t reg;

    if(handle == NULL)
    {
        return DA7281_RET_ERROR;
    }

    uint16_t *v2i_factor;
    if(da7281_get_v2i_factor(handle, v2i_factor) == DA7281_OK)
    {
        uint8_t *imax;
        if(da7281_get_actuator_imax(handle, imax) == DA7281_OK)
        {
            *value = ((*v2i_factor * 1.6104) / (*imax + 4));   /*V2𝐼_𝐹𝐴𝐶𝑇𝑂𝑅[15:0] = 𝑍× (𝐼𝑀𝐴𝑋[4:0]+4) / 1.6104*/
        }
    }

    else
    {
        return DA7281_RET_ERROR;
    }

    return DA7281_OK;
}

/*
*Set LRA_PER_H - LRA resonant frequency
*/
int8_t da7281_set_lra_per_h(da7281_handle_t *handle, uint8_t value)
{
    
}






