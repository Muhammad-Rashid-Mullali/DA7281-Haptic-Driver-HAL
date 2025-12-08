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

    }
}
uint8_t da7281_init(da7281_handle_t *handle)
{
    uint8_t rslt;
    uint8_t prev;
    
    if(handle == NULL)
    {
        return 1;
    }

    

}

