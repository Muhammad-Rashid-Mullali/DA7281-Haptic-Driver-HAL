#include <stdio.h>
#include <stdint.h>
#include "da7281.h"
#include "da7281_bit_defs.h"

static void check_chip_rev(da7281_handle_t *handle)
{
}

static int8_t reg_read_write(uint8_t reg_addr, uint8_t *reg_data, uint32_t len, struct da7281_handle *handle, uint8_t select);

static int8_t reg_read_write(uint8_t reg_addr, uint8_t *reg_data, uint32_t len, struct da7281_handle *handle, uint8_t select)
{
    int8_t rslt = DA7281_OK;
    uint16_t index;
    uint8_t temp_buff[DA7281_MAX_LEN];

    if(select == DA7281_READ)
    {
        handle->i2c_rslt = handle->iic_read

    }
}
uint8_t da7281_init(da7281_handle_t *handle)
{
    uint8_t chip_rev;
    
    if(handle == NULL)
    {
        return DA7281_RET_NULL_ERROR;
    }

    /****************Need to check the completion of boot after 1.5ms using Suitable Timing**************/

    handle->i2c_rslt = handle->iic_read(DA7281_REG_CHIP_REV, &chip_rev, DA7281_REG_BYTE);
    if(handle->i2c_rslt == DA7281_I2C_RET_SUCCESS)
    {
        if(chip_rev != DA7281_DEFAULT_CHIP_REV)
        {
            return DA7281_RET_ERROR;
        }
    }
    
    uint8_t op_mode = NULL;
    op_mode |= op_mode << 0;
    handle->i2c_rslt = handle->iic_write(DA7281_REG_TOP_CTL1, &op_mode, DA7281_REG_BYTE);
    if (handle->i2c_rslt != DA7281_I2C_RET_SUCCESS)
    {
        return DA7281_I2C_RET_ERROR;
    }
    
    
    else
    {
        return DA7281_I2C_RET_ERROR;
    }
}

