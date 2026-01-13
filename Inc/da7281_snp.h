#include <stdint.h>

/*
*Header file for Waveform Memory Snippets related Registers
*/

#define TOTAL_SNP_MEM_BYTES                 UINT8_C(100)
#define TOTAL_SNP_MEM_SEQUENCE              UINT8_C(15)
#define TOTAL_SNP_MEM_SNIPPET               UINT8_C(16)

#define DA7281_REG_SNP_MEM_0                UINT8_C(0x84)
#define DA7281_REG_SNP_MEM_1                UINT8_C(0x85)
#define DA7281_REG_SNP_MEM_2                UINT8_C(0X86)
#define DA7281_REG_SNP_MEM_3                UINT8_C(0x87)
#define DA7281_REG_SNP_MEM_4                UINT8_C(0x88)
#define DA7281_REG_SNP_MEM_5                UINT8_C(0x89)
#define DA7281_REG_SNP_MEM_6                UINT8_C(0x8A)
#define DA7281_REG_SNP_MEM_7                UINT8_C(0x8B)
#define DA7281_REG_SNP_MEM_8                UINT8_C(0x8C)
#define DA7281_REG_SNP_MEM_9                UINT8_C(0x8D)
#define DA7281_REG_SNP_MEM_10               UINT8_C(0x8E)
#define DA7281_REG_SNP_MEM_11               UINT8_C(0x8F)
#define DA7281_REG_SNP_MEM_12               UINT8_C(0x90)
#define DA7281_REG_SNP_MEM_13               UINT8_C(0x91)
#define DA7281_REG_SNP_MEM_14               UINT8_C(0x92)
#define DA7281_REG_SNP_MEM_15               UINT8_C(0x93)
#define DA7281_REG_SNP_MEM_16               UINT8_C(0x94)
#define DA7281_REG_SNP_MEM_17               UINT8_C(0x95)
#define DA7281_REG_SNP_MEM_18               UINT8_C(0x96)
#define DA7281_REG_SNP_MEM_19               UINT8_C(0x97)
#define DA7281_REG_SNP_MEM_20               UINT8_C(0x98)
#define DA7281_REG_SNP_MEM_21               UINT8_C(0x99)
#define DA7281_REG_SNP_MEM_22               UINT8_C(0x9A)
#define DA7281_REG_SNP_MEM_23               UINT8_C(0x9B)
#define DA7281_REG_SNP_MEM_24               UINT8_C(0x9C)
#define DA7281_REG_SNP_MEM_25               UINT8_C(0x9D)
#define DA7281_REG_SNP_MEM_26               UINT8_C(0x9E)
#define DA7281_REG_SNP_MEM_27               UINT8_C(0x9F)
#define DA7281_REG_SNP_MEM_28               UINT8_C(0xA0)
#define DA7281_REG_SNP_MEM_29               UINT8_C(0xA1)
#define DA7281_REG_SNP_MEM_30               UINT8_C(0xA2)
#define DA7281_REG_SNP_MEM_31               UINT8_C(0xA3)
#define DA7281_REG_SNP_MEM_32               UINT8_C(0xA4)
#define DA7281_REG_SNP_MEM_33               UINT8_C(0xA5)
#define DA7281_REG_SNP_MEM_34               UINT8_C(0xA6)
#define DA7281_REG_SNP_MEM_35               UINT8_C(0xA7)
#define DA7281_REG_SNP_MEM_36               UINT8_C(0xA8)
#define DA7281_REG_SNP_MEM_37               UINT8_C(0xA9)
#define DA7281_REG_SNP_MEM_38               UINT8_C(0xAA)
#define DA7281_REG_SNP_MEM_39               UINT8_C(0xAB)
#define DA7281_REG_SNP_MEM_40               UINT8_C(0xAC)
#define DA7281_REG_SNP_MEM_41               UINT8_C(0xAD)
#define DA7281_REG_SNP_MEM_42               UINT8_C(0xAE)
#define DA7281_REG_SNP_MEM_43               UINT8_C(0xAF)
#define DA7281_REG_SNP_MEM_44               UINT8_C(0xB0)
#define DA7281_REG_SNP_MEM_45               UINT8_C(0xB1)
#define DA7281_REG_SNP_MEM_46               UINT8_C(0xB2)
#define DA7281_REG_SNP_MEM_47               UINT8_C(0xB3)
#define DA7281_REG_SNP_MEM_48               UINT8_C(0xB4)
#define DA7281_REG_SNP_MEM_49               UINT8_C(0xB5)
#define DA7281_REG_SNP_MEM_50               UINT8_C(0xB6)
#define DA7281_REG_SNP_MEM_51               UINT8_C(0xB7)
#define DA7281_REG_SNP_MEM_52               UINT8_C(0xB8)
#define DA7281_REG_SNP_MEM_53               UINT8_C(0xB9)
#define DA7281_REG_SNP_MEM_54               UINT8_C(0xBA)
#define DA7281_REG_SNP_MEM_55               UINT8_C(0xBB)
#define DA7281_REG_SNP_MEM_56               UINT8_C(0xBC)
#define DA7281_REG_SNP_MEM_57               UINT8_C(0xBD)
#define DA7281_REG_SNP_MEM_58               UINT8_C(0xBE)
#define DA7281_REG_SNP_MEM_59               UINT8_C(0xBF)
#define DA7281_REG_SNP_MEM_60               UINT8_C(0xC0)
#define DA7281_REG_SNP_MEM_61               UINT8_C(0xC1)
#define DA7281_REG_SNP_MEM_62               UINT8_C(0xC2)
#define DA7281_REG_SNP_MEM_63               UINT8_C(0xC3)
#define DA7281_REG_SNP_MEM_64               UINT8_C(0xC4)
#define DA7281_REG_SNP_MEM_65               UINT8_C(0xC5)
#define DA7281_REG_SNP_MEM_66               UINT8_C(0xC6)
#define DA7281_REG_SNP_MEM_67               UINT8_C(0xC7)
#define DA7281_REG_SNP_MEM_68               UINT8_C(0xC8)
#define DA7281_REG_SNP_MEM_69               UINT8_C(0xC9)
#define DA7281_REG_SNP_MEM_70               UINT8_C(0xCA)
#define DA7281_REG_SNP_MEM_71               UINT8_C(0xCB)
#define DA7281_REG_SNP_MEM_72               UINT8_C(0xCC)
#define DA7281_REG_SNP_MEM_73               UINT8_C(0xCD)
#define DA7281_REG_SNP_MEM_74               UINT8_C(0xCE)
#define DA7281_REG_SNP_MEM_75               UINT8_C(0xCF)
#define DA7281_REG_SNP_MEM_76               UINT8_C(0xD0)
#define DA7281_REG_SNP_MEM_77               UINT8_C(0xD1)
#define DA7281_REG_SNP_MEM_78               UINT8_C(0xD2)
#define DA7281_REG_SNP_MEM_79               UINT8_C(0xD3)
#define DA7281_REG_SNP_MEM_80               UINT8_C(0xD4)
#define DA7281_REG_SNP_MEM_81               UINT8_C(0xD5)
#define DA7281_REG_SNP_MEM_82               UINT8_C(0xD6)
#define DA7281_REG_SNP_MEM_83               UINT8_C(0xD7)
#define DA7281_REG_SNP_MEM_84               UINT8_C(0xD8)
#define DA7281_REG_SNP_MEM_85               UINT8_C(0xD9)
#define DA7281_REG_SNP_MEM_86               UINT8_C(0xDA)
#define DA7281_REG_SNP_MEM_87               UINT8_C(0xDB)
#define DA7281_REG_SNP_MEM_88               UINT8_C(0xDC)
#define DA7281_REG_SNP_MEM_89               UINT8_C(0xDD)
#define DA7281_REG_SNP_MEM_90               UINT8_C(0xDE)
#define DA7281_REG_SNP_MEM_91               UINT8_C(0xDF)
#define DA7281_REG_SNP_MEM_92               UINT8_C(0xE0)
#define DA7281_REG_SNP_MEM_93               UINT8_C(0xE1)
#define DA7281_REG_SNP_MEM_94               UINT8_C(0xE2)
#define DA7281_REG_SNP_MEM_95               UINT8_C(0xE3)
#define DA7281_REG_SNP_MEM_96               UINT8_C(0xE4)
#define DA7281_REG_SNP_MEM_97               UINT8_C(0xE5)
#define DA7281_REG_SNP_MEM_98               UINT8_C(0xE6)
#define DA7281_REG_SNP_MEM_99               UINT8_C(0xE7)


/*Frame structure*/
typedef struct da7281_frame
{
    uint8_t snippet_id;
    uint8_t amplitude;
    uint8_t times;
}da7281_frame_t;



/*
*SNP Related Enumerations and BIT Definitions
*/

typedef enum{
    DA7281_SNP_GAIN_00 =                     UINT8_C(0x00),
    DA7281_SNP_GAIN_01 =                     UINT8_C(0x01),
    DA7281_SNP_GAIN_10 =                     UINT8_C(0x02),
    DA7281_SNP_GAIN_11 =                     UINT8_C(0x03)
} da7281_snp_gain_t;

/*
|---------------------------------------------------------|
|    TIMEBASE Depends on FREQ_WAVEFORM_TIMEBASE value     |
|---------------------------------------------------------|
|FREQ_WAVEFORM_TIMEBASE = 0  |  FREQ_WAVEFORM_TIMEBASE = 1|
|---------------------------------------------------------|
|TIMEBASE_00  =  5.44 ms     |  TIMEBASE_00  =  1.36 ms   |
|TIMEBASE_01  =  21.76 ms    |  TIMEBASE_01  =  5.44 ms   |
|TIMEBASE_10  =  43.52 ms    |  TIMEBASE_10  =  21.76 ms  |
|TIMEBASE_11  =  87.04 ms    |  TIMEBASE_11  =  43.52 ms  |
|---------------------------------------------------------|
*/
typedef enum{
    DA7281_SNP_TIMEBASE_00 =                 UINT8_C(0x00),
    DA7281_SNP_TIMEBASE_01 =                 UINT8_C(0x01),
    DA7281_SNP_TIMEBASE_10 =                 UINT8_C(0x02),
    DA7281_SNP_TIMEBASE_11 =                 UINT8_C(0x03)
} da7281_snp_timebase_t;

