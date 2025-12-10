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
        /* code */
    }

    if (reg & (DA7281_BIT_ENABLE << STA_UVLO_VBAT_OK))
    {
        /* code */
    }

    if (reg & (DA7281_BIT_ENABLE << STA_PAT_DONE))
    {
        /* code */
    }

    if (reg & (DA7281_BIT_ENABLE << STA_OVERTEMP_CRIT))
    {
        /* code */
    }

    if (reg & (DA7281_BIT_ENABLE << STA_PAT_FAULT))
    {
        da7281_irq_sequence_t seq;

        if(handle->iic_read(DA7281_REG_IRQ_EVENT_SEQ_DIAG, &seq, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
        {
            if(seq & (DA7281_BIT_ENABLE << E_PWM_FAULT))
            {
                /* CODE */
            }

            if(seq & (DA7281_BIT_ENABLE << E_MEM_FAULT))
            {
                /* CODE */
            }

            if(seq & (DA7281_BIT_ENABLE << E_SEQ_ID_FAULT))
            {
                /* CODE */
            }
        }
    }

    if (reg & (DA7281_BIT_ENABLE << STA_WARNING))
    {
        da7281_irq_warnings_t warning;

        if(handle->iic_read(DA7281_REG_IRQ_EVENT_WARNING_DIAG, &warning, DA7281_REG_BYTE) != DA7281_I2C_RET_ERROR)
        {
            if(warning & (DA7281_BIT_ENABLE << E_OVERTEMP_WARN))
            {
                /* CODE */
            }

            if(warning & (DA7281_BIT_ENABLE << E_MEM_TYPE))
            {
                /* CODE */
            }

            if(warning & (DA7281_BIT_ENABLE << E_LIM_DRIVE_ACC))
            {
                /* CODE */
            }

            if(warning & (DA7281_BIT_ENABLE << E_LIM_DRIVE))
            {
                /* CODE */
            }
        }

        else
        {
            return DA7281_I2C_RET_ERROR;
        }
    }

    if (reg & (DA7281_BIT_ENABLE << STA_ACTUATOR))
    {
        /* code */
    }

      if (reg & (DA7281_BIT_ENABLE << STA_OC))
    {
        /* code */
    }

  
}



