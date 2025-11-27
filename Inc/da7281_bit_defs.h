/*
*This files contains the definitions of enumerations for each bits
*/

/*
*Default value defines
*/
#define DA7281_DEFAULT_LRA_AVR_H                UINT8_C(0x21)
#define DA7281_DEFAULT_LRA_PER_L                UINT8_C(0x4F)
#define DA7281_DEFAULT_ACTUATOR_NOMMAX          UINT8_C(0x5A)
#define DA7281_DEFAULT_ACTUATOR_ABSMAX          UINT8_C(0x78)
#define DA7281_DEFAULT_IMAX                     UINT8_C(0x17)
#define DA7281_DEFAULT_V2I_FACTOR_H             UINT8_C(0x01)
#define DA7281_DEFAULT_V2I_FACTOR_L             UINT8_C(0x0D)
#define DA7281_DEFAULT_IMPEDANCE_H              UINT8_C(0x00)
#define DA7281_DEFAULT_IMPEDANCE_L              UINT8_C(0x00)

#define DA7281_DEFAULT_ADC_VDD_H                UINT8_C(0xFF)
#define DA7281_DEFAULT_ADC_VDD_L                UINT8_C(0x7F)

#define DA7281_DEFAULT_LRA_PER_ACTUAL_H         UINT8_C(0x21)
#define DA7281_DEFAULT_LRA_PER_ACTUAL_L         UINT8_C(0x4F)

#define DA7281_DEFAULT_DELAY_H                  UINT8_C(0x25) /*  Setting for closed-loop frequency tracking mode */

#define DA7281_DEFAULT_DELAY_SHIFT_L            UINT8_C(0x05)

/*
*@breif Actuator Type Mode
*/
#define DA7281_ACTUATOR_MODE_LRA                UINT8_C(0x00)
#define DA7281_ACTUATOR_MODE_ERM                UINT8_C(0x01)

/*
*@brief Bit Enable and Disable
*/
#define DA7281_BIT_DISABLE                      UINT8_C(0x00)
#define DA7281_BIT_ENABLE                       UINT8_C(0x01)

/*
*@brief Enumeration for FULL_BRAKE_THR Bit
*/
typedef enum{
    DA7281_BRAKE_THESHOLD_DISABLED =            UINT8_C(0x00),
    DA7281_BRAKE_THRESHOLD_ONE,
    DA7281_BRAKE_THRESHOLD_TWO,
    DA7281_BRAKE_THRESHOLD_THREE,
    DA7281_BRAKE_THESHOLD_FOUR,
    DA7281_BRAKE_THESHOLD_FIVE,
    DA7281_BRAKE_THRESHOLD_SIX,
    DA7281_BRAKE_THESHOLD_SEVEN,
    DA7281_BRAKE_THRESHOLD_EIGHT,
    DA7281_BRAKE_THRESHOLD_NINE,
    DA7281_BRAKE_THESHOLD_TEN,
    DA7281_BRAKE_THESHOLD_ELEVEN,
    DA7281_BRAKE_THRESHOLD_TWELVE,
    DA7281_BRAKE_THRESHOLD_THIRTEEN,
    DA7281_BRAKE_THESHOLD_FOURTEEN,
    DA7281_BRAKE_THRESHOLD_FIFTEEN =            UINT8_C(0x0F)
} da7281_brake_thr_t;

/*
*@brief Enumeration for VDD_MARGIN Bit
*/
typedef enum{
    DA7281_VDD_MARGIN_LOW =                     UINT8_C(0x00),
    DA7281_VDD_MARGIN_ONE,
    DA7281_VDD_MARGIN_TWO,
    DA7281_VDD_MARGIN_THREE,
    DA7281_VDD_MARGIN_FOUR,
    DA7281_VDD_MARGIN_FIVE,
    DA7281_VDD_MARGIN_SIX,
    DA7281_VDD_MARGIN_SEVEN,
    DA7281_VDD_MARGIN_EIGHT,
    DA7281_VDD_MARGIN_NINE,
    DA7281_VDD_MARGIN_TEN,
    DA7281_VDD_MARGIN_ELEVEN,
    DA7281_VDD_MARGIN_TWELVE,
    DA7281_VDD_MARGIN_THIRTEEN,
    DA7281_VDD_MARGIN_FOUTEEN,
    DA7281_VDD_MARGIN_HIGH =                    UINT8_C(0x0F)
} da7281_vdd_margin_t;

/*
*@breif Enumeration for BEMF_FAULT_LIM Bit
*/
typedef enum{
    DA7281_BEM_FAULT_LIM_DISABLED =            UINT8_C(0x00),
    DA7281_BEM_FAULT_LIM_ONE,
    DA7281_BEM_FAULT_LIM_TWO,
    DA7281_BEM_FAULT_LIM_THREE =               UINT8_C(0x03)
} da7281_bem_fault_lim_t;

/*
*@breif Enumeration for OPERATION_MODE Bit
*/
typedef enum{
    DA7281_OPERATION_MODE_INACTIVE =           UINT8_C(0x00),
    DA7281_OPERATION_MODE_DRO,
    DA7281_OPERATION_MODE_PWM,
    DA7281_OPERATION_MODE_RTWM,
    DA7281_OPERATION_MODE_ETWM =               UINT8_C(0x04)
} da7281_operation_mode_t;

/*
*@brief Enumerations for PS_SEQ_LOOP Bit
*/
typedef enum{
    DA7281_PS_SEQ_LOOP_ZERO =                  UINT8_C(0x00), 
    DA7281_PS_SEQ_LOOP_ONE =                   UINT8_C(0x01), 
    DA7281_PS_SEQ_LOOP_TWO =                   UINT8_C(0x02), 
    DA7281_PS_SEQ_LOOP_THREE =                 UINT8_C(0x03), 
    DA7281_PS_SEQ_LOOP_FOUR =                  UINT8_C(0x04), 
    DA7281_PS_SEQ_LOOP_FIVE =                  UINT8_C(0x05), 
    DA7281_PS_SEQ_LOOP_SIX =                   UINT8_C(0x06), 
    DA7281_PS_SEQ_LOOP_SEVEN =                 UINT8_C(0x07), 
    DA7281_PS_SEQ_LOOP_EIGHT =                 UINT8_C(0x08), 
    DA7281_PS_SEQ_LOOP_NINE =                  UINT8_C(0x09), 
    DA7281_PS_SEQ_LOOP_TEN =                   UINT8_C(0x0A), 
    DA7281_PS_SEQ_LOOP_ELEVEN =                UINT8_C(0x0B), 
    DA7281_PS_SEQ_LOOP_TWELVE =                UINT8_C(0x0C), 
    DA7281_PS_SEQ_LOOP_THIRTEEN =              UINT8_C(0x0D), 
    DA7281_PS_SEQ_LOOP_FOURTEEN =              UINT8_C(0x0E), 
    DA7281_PS_SEQ_LOOP_FIFTEEN =               UINT8_C(0x0F)
} da7281_ps_seq_loop_t;

/*
*@brief Enumerations for GPI_POLARITY Bit
*/
typedef enum{
    DA7281_GPI_POLARITY_RISING_EDGE =               UINT8_C(0x00), 
    DA7281_GPI_POLARITY_FALLING_EDGE =              UINT8_C(0x01), 
    DA7281_GPI_POLARITY_BOTH_EDGE =                 UINT8_C(0x02)
} da7281_gpi_polarity_t;

/*
*@breif Enumerations for REF_UVLO_THRES Bit
*/
typedef enum{
    DA7281_REF_UVLO_THRES_00 =                      UINT8_C(0x00), /* UVLO threshold 2.7V*/
    DA7281_REF_UVLO_THRES_01 =                      UINT8_C(0x01), /* UVLO threshold 2.8V (Default) */
    DA7281_REF_UVLO_THRES_10 =                      UINT8_C(0x10), /* UVLO threshold 2.9V */
    DA7281_REF_UVLO_THRES_11 =                      UINT8_C(0x11)  /* UVLO threshold 3.0V */
} da7281_ref_uvlo_thres_t;

/*
*@brief Enumerations for HBRIDGE_ERC_LS_TRIM Bit
*/
typedef enum{
    DA7281_HBRIDGE_ERC_LS_TRIM_00 =                 UINT8_C(0x00), /* Low side Edge Rate Control 25mV/ns */
    DA7281_HBRIDGE_ERC_LS_TRIM_01 =                 UINT8_C(0x01), /* Low side Edge Rate Control 50mV/ns */
    DA7281_HBRIDGE_ERC_LS_TRIM_10 =                 UINT8_C(0x10), /* Low side Edge Rate Control 75mV/ns */
    DA7281_HBRIDGE_ERC_LS_TRIM_11 =                 UINT8_C(0x11)  /* Low side Edge Rate Control 100mV/ns (Default)*/
} da7281_hbridge_erc_ls_trim_t;

/*
*@brief Enumerations for HBRIDGE_ERC_HS_TRIM Bit
*/
typedef enum{
    DA7281_HBRIDGE_ERC_HS_TRIM_00 =                 UINT8_C(0x00), /* High side Edge Rate Control 25mV/ns */
    DA7281_HBRIDGE_ERC_HS_TRIM_01 =                 UINT8_C(0x01), /* High side Edge Rate Control 50mV/ns */
    DA7281_HBRIDGE_ERC_HS_TRIM_10 =                 UINT8_C(0x10), /* High side Edge Rate Control 75mV/ns */
    DA7281_HBRIDGE_ERC_HS_TRIM_11 =                 UINT8_C(0x11)  /* High side Edge Rate Control 100mV/ns (Default)*/
}