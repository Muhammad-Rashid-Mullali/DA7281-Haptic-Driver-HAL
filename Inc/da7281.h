#include <stdint.h>
#include <stdio.h>

#define DA7281_BOOL_TRUE                        UINT8_C(0x01)
#define DA7281_BOOL_FALSE                       UINT8_C(0x00)

/*DA7281 Register Address*/
#define DA7281_REG_CHIP_REV                     UINT8_C(0x00)
#define DA7281_REG_IRQ_EVENT1                   UINT8_C(0x03)
#define DA7281_REG_IRQ_EVENT_WARNING_DIAG       UINT8_C(0x04)
#define DA7281_REG_IRQ_EVENT_SEQ_DIAG           UINT8_C(0x05)
#define DA7281_REG_IRQ_STATUS1                  UINT8_C(0x06)
#define DA7281_REG_IRQ_MASK1                    UINT8_C(0x07)
#define DA7281_REG_CIF_I2C1                     UINT8_C(0x08)
#define DA7281_REG_CIF_I2C2                     UINT8_C(0x09)
#define DA7281_REG_FRQ_LRA_PER_H                UINT8_C(0x0A)
#define DA7281_REG_FRQ_LRA_PER_L                UINT8_C(0x0B)
#define DA7281_REG_ACTUATOR1                    UINT8_C(0x0C)
#define DA7281_REG_ACTUATOR2                    UINT8_C(0x0D)
#define DA7281_REG_ACTUATOR3                    UINT8_C(0x0E)
#define DA7281_REG_CALIB_V2I_H                  UINT8_C(0x0F)
#define DA7281_REG_CALIB_V2I_L                  UINT8_C(0x10)
#define DA7281_REG_CALIB_IMP_H                  UINT8_C(0x11)
#define DA7281_REG_CALIB_IMP_L                  UINT8_C(0x12)
#define DA7281_REG_TOP_CFG1                     UINT8_C(0x13)
#define DA7281_REG_TOP_CFG2                     UINT8_C(0x14)
#define DA7281_REG_TOP_CFG3                     UINT8_C(0x15)
#define DA7281_REG_TOP_CFG4                     UINT8_C(0x16)
#define DA7281_REG_TOP_INT_CFG1                 UINT8_C(0x17)
#define DA7281_REG_TOP_INT_CFG6_H               UINT8_C(0x1C)
#define DA7281_REG_TOP_INT_CFG6_L               UINT8_C(0x1D)
#define DA7281_REG_TOP_INT_CFG7_H               UINT8_C(0x1E)
#define DA7281_REG_TOP_INT_CFG7_L               UINT8_C(0x1F)
#define DA7281_REG_TOP_INT_CFG8                 UINT8_C(0x20)
#define DA7281_REG_TOP_CTL1                     UINT8_C(0x22)
#define DA7281_REG_TOP_CTL2                     UINT8_C(0x23)
#define DA7281_REG_SEQ_CTL1                     UINT8_C(0x24)
#define DA7281_REG_SWG_C1                       UINT8_C(0x25)
#define DA7281_REG_SWG_C2                       UINT8_C(0x26)
#define DA7281_REG_SWG_C3                       UINT8_C(0x27)
#define DA7281_REG_SEQ_CTL2                     UINT8_C(0x28)
#define DA7281_REG_GPI_CTL                      UINT8_C(0x2B)
#define DA7281_REG_MEM_CTL1                     UINT8_C(0x2C)
#define DA7281_REG_MEM_CTL2                     UINT8_C(0x2D)
#define DA7281_REG_ADC_DATA_H1                  UINT8_C(0x2E)
#define DA7281_REG_ADC_DATA_L1                  UINT8_C(0x2F)
#define DA7281_REG_POLARITY                     UINT8_C(0x43)
#define DA7281_REG_LRA_AVR_H                    UINT8_C(0x44)
#define DA7281_REG_LRA_AVR_L                    UINT8_C(0x45)
#define DA7281_REG_FRQ_LRA_PER_ACT_H            UINT8_C(0x46)
#define DA7281_REG_FRQ_LRA_PER_ACT_L            UINT8_C(0x47)
#define DA7281_REG_FRQ_PHASE_H                  UINT8_C(0x48)
#define DA7281_REG_FRQ_PHASE_L                  UINT8_C(0x49)
#define DA7281_REG_FRQ_CTL                      UINT8_C(0x4C)
#define DA7281_REG_TRIM3                        UINT8_C(0x5F)
#define DA7281_REG_TRIM4                        UINT8_C(0x60)
#define DA7281_REG_TRIM6                        UINT8_C(0x62)
#define DA7281_REG_TOP_CFG5                     UINT8_C(0x6E)
#define DA7281_REG_IRQ_EVENT_ACTUATOR_FAULT     UINT8_C(0x81)
#define DA7281_REG_IRQ_STATUS2                  UINT8_C(0x82)
#define DA7281_REG_IRQ_MASK2                    UINT8_C(0x83)

/*Register Address to Store Waveform Memory*/
typedef enum {
    DA7281_REG_SNP_MEM_0 =                      UINT8_C(0x84),
    DA7281_REG_SNP_MEM_1 =                      UINT8_C(0x85),
    DA7281_REG_SNP_MEM_2 =                      UINT8_C(0x86),
    DA7281_REG_SNP_MEM_98 =                     UINT8_C(0xE6),
    DA7281_REG_SNP_MEM_99 =                     UINT8_C(0xE7),
} da7281_snp_mem_t;

git


