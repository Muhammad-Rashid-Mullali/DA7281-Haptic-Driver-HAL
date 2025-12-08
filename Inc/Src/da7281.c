#include <stdio.h>
#include <stdint.h>
#include "da7281.h"
#include "da7281_bit_defs.h"

static void check_chip_rev(da7281_handle *handle)
{
}

uint8_t da7281_init(da7281_handle *handle)
{
    uint8_t rslt;
    uint8_t prev;
    
    if(handle == NULL)
    {
        return 1;
    }

    check_chip_rev();

}