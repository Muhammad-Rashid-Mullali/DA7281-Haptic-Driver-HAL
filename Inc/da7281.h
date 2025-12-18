#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "da7281_bit_defs.h"

/*Enable/Disable macros*/
#define DA7281_BOOL_TRUE                        UINT8_C(0x01)
#define DA7281_BOOL_FALSE                       UINT8_C(0x00)

/*API Return code*/
#define DA7281_OK                               INT8_C(0)
#define DA7281_RET_ERROR                        INT8_C(-1)
#define DA7281_RET_NULL_ERROR                   INT8_C(-2)
#define DA7281_RET_VALUE_ERROR                  INT8_C(-3)

#define DA7281_MAX_LEN                          UINT8_C(0x80)  //128 in decimal

/* Macros for Read/Write*/
#define DA7281_READ                             UINT8_C(0)
#define DA7281_WRITE                            UINT8_C(1)

/* Macros Interfaces */
#define DA7281_I2C_INTF                         UINT8_C(0)
#define DA7281_REG_BYTE                         UINT8_C(1)
#define DA7281_I2C_RET_SUCCESS                  UINT8_C(0)
#define DA7281_I2C_RET_ERROR                    UINT8_C(1)

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

/***************************REGISTER BIT DEFINITIONS************************/

/*
*@brief IRQ Events
*/
typedef enum {
    E_SEQ_CONTINUE =                            UINT8_C(0x00), /* IRQ indicating that playback of a new sequence has occurred
                                                                  because SEQ_CONTINUE is set to 1 */

    E_UVLO =                                    UINT8_C(0x01), /* Under-voltage fault, supply below the UVLO threshold
                                                                  Clear to attempt restart */

    E_SEQ_DONE =                                UINT8_C(0x02), /* IRQ indicating that sequence playback from waveform memory
                                                                  is complete */

    E_OVERTEMP_CRIT =                           UINT8_C(0x03), /* Critical chip temperature event, chip temperature has exceeded
                                                                  the critical limit of 125 °C */

    E_SEQ_FAULT =                               UINT8_C(0x04), /* Sequence faults: SEQ_ID_FAULT, memory fault or PWM fault
                                                                  Read IRQ_EVENT_SEQ_DIAG for diagnostic information */

    E_WARNING =                                 UINT8_C(0x05), /* System warnings
                                                                  Read IRQ_EVENT_WARNING_DIAG for warning diagnostic */

    E_ACTUATOR_FAULT =                          UINT8_C(0x06), /* Issue detected with the actuator impedance, BEMF amplitude,
                                                                  or resonant frequency */

    E_OC_FAULT =                                UINT8_C(0x07)  /* Over-current / short-circuit fault on the OUTP or OUTN pin */
} da7281_irq_events_t;

/*
*@brief IRQ Event Warnings
*/
typedef enum {
    E_OVERTEMP_WARN =                           UINT8_C(0x03), /* Over-temperature warning, chip temperature has exceeded
                                                                  the warning limit of 105 °C (write 1 to E_WARNING to clear) */

    E_MEM_TYPE =                                UINT8_C(0x04), /* Indicates that the memory data type configured in register 
                                                                  MEM_DATA_SIGNED does not match the acceleration configuration
                                                                  (ACCELERATION_EN) */

    E_LIM_DRIVE_ACC =                           UINT8_C(0x06), /* IRQ indicating that acceleration is limited because the power
                                                                  supply level is lower than required for the acceleration target */

    E_LIM_DRIVE =                               UINT8_C(0x07)  /* IRQ indicating that playback is limited because the power supply
                                                                  level is lower than the sequence target*/
} da7281_irq_warnings_t;

/*
*@brief IRQ Event Sequences
*/
typedef enum {
    E_PWM_FAULT =                               UINT8_C(0x05), /* IRQ indicating that the PWM input signal has timed out
                                                                  write 1 to E_SEQ_FAULT to clear */

    E_MEM_FAULT =                               UINT8_C(0x06), /* Indicates that the Waveform Memory is corrupted
                                                                  write 1 to E_SEQ_FAULT to clear */

    E_SEQ_ID_FAULT =                            UINT8_C(0x07)  /* IRQ indicating that requested sequence ID configured
                                                                  in PS_SEQ_ID is not valid
                                                                  write 1 to E_SEQ_FAULT to clear */
} da7281_irq_sequence_t;

/*
*@breif IRQ Status
*/
typedef enum {
    STA_SEQ_CONTINUE =                          UINT8_C(0x00), /* Continuous sequence status */

    STA_UVLO_VBAT_OK =                          UINT8_C(0x01), /* UVLO output status: 0 during normal operation
                                                                  1 if thereis a UVLO event */

    STA_PAT_DONE =                              UINT8_C(0x02), /* Memory based sequence status */

    STA_OVERTEMP_CRIT =                         UINT8_C(0x03), /* Over-temperature status */

    STA_PAT_FAULT =                             UINT8_C(0x04), /* Sequence faults status */

    STA_WARNING =                               UINT8_C(0x05), /* System warnings status */

    STA_ACTUATOR =                              UINT8_C(0x06), /* Actuator fault status */

    STA_OC =                                    UINT8_C(0x07)  /* Over-current / short circuit fault status */
} da7281_irq_status_t;

/*
*@brief IRQ Masks
*/
typedef enum{
    SEQ_CONTINUE_M =                            UINT8_C(0x00), /* Continuous sequence interrupt mask */

    E_UVLO_M =                                  UINT8_C(0x01), /* Soft shutdown fault mask */

    SEQ_DONE_M =                                UINT8_C(0x02), /* Memory based sequence interrupt mask */

    OVERTEMP_CRIT_M =                           UINT8_C(0x03), /* Over-temperature fault mask */

    SEQ_FAULT_M =                               UINT8_C(0x04), /* Sequence faults mask */

    WARNING_M =                                 UINT8_C(0x05), /* System warnings mask */

    ACTUATOR_M =                                UINT8_C(0x06), /* Actuator fault mask */

    OC_M =                                      UINT8_C(0x07)  /* Over-current / short circuit fault mask */
} da7281_irq_mask_t;

/*
*@brief I2C Specific
*/
typedef enum{
    IF_BASE_ADDR =                              UINT8_C(0X00), /* I2C base address */

    I2C_TO_ENABLE =                             UINT8_C(0x06), /* I2C timeout enable. If there are no negative edges on
                                                                  SCL for approx. 35 ms, the slave resets */

    I2C_WR_MODE =                               UINT8_C(0X07)  /* I2C write mode */
} da7281_i2c_t;

/*
*@breif DA7281 TOP Configuration 1
*/
typedef enum{
    AMP_PID_EN =                                UINT8_C(0x00), /* Enable Amplitude PID */

    RAPID_STOP_EN =                             UINT8_C(0x01), /* Enable Rapid Stop */

    ACCELERATION_EN =                           UINT8_C(0x02), /* Enable Active Acceleration */

    FREQ_TRACK_EN =                             UINT8_C(0x03), /* Enable resonant frequency tracking; ignored in ERM mode */
    
    BEMF_SENSE_EN =                             UINT8_C(0x04), /* Enable internal loop computations; should be disabled only in
                                                                  custom waveform and wideband operation */

    ACTUATOR_TYPE =                             UINT8_C(0x05), /* Specifies actuator type: LRA or ERM */

    EMBEDDED_MODE =                             UINT8_C(0x07)  /* Embedded operation enable */
} da7281_top_cfg1_t;

/*
*@breif DA7281 TOP Control 1
*/
typedef enum{
    OPERATION_MODE =                            UINT8_C(0x00), /* Haptic operation mode */

    STANDBY_EN =                                UINT8_C(0x03), /* Sets the state DA7281 returns to after completion of playback */

    SEQ_START =                                 UINT8_C(0x04) /* Start/stop control of Waveform Memory sequence playback */
} da7281_top_ctl1;

/*
*@breif DA7281 TOP Configuration 2
*/
typedef enum{
    FULL_BRAKE_THR =                            UINT8_C(0x00), /* Full-brake threshold for PWM mode with step size 6.66% */

    MEM_DATA_SIGNED =                           UINT8_C(0x04), /* Memory data format; set according to the value of ACCELERATION_EN*/
} da7281_top_cfg2_t;

/*
*@breif Power States
*/
#define DA7281_IDLE_STATE                       UINT8_C(0x00)
#define DA7281_STANDBY_STATE                    UINT8_C(0x01)
#define DA7281_DRIVE_STATE                      UINT8_C(0x02)


/*!
 *  @brief DA7281 Initialization
 */
int8_t da7281_init(da7281_handle_t *handle);

/*!
 *  @brief DA7281 IRQ Handler
 */
int8_t da7281_irq_handler(da7281_handle_t *handle);

/*!
* @breif DA7281 Configure Actuator Setup
* @handle : Device handle struct
* @type : LRA - 0 ; ERM - 1
*/
int8_t da7281_select_actuator_type(da7281_handle_t *handle, bool type);

/*
* @breif Set Actuator Nominal maximum voltage
* @handle : Device handle struct
* @value : The allowable range from 0 V to 6 V in 23.4 mV steps
*/
int8_t da7281_set_actuator_nommax(da7281_handle_t* handle, uint8_t value);

/*
* @breif Get Actuator nominal maximum voltage
* @handle : Device handle struct
* @value : Default value is @DA7281_DEFAULT_ACTUATOR_NOMMAX of 23.4 mV steps
*/
int8_t da7281_get_actuator_nommax(da7281_handle_t* handle, uint8_t *value);

/*
* @breif Set Actuator absolute maximum voltage
* @handle : Device handle struct
* @value : The allowable range from 0 V to 6 V in 23.4 mV steps
*/
int8_t da7281_set_actuator_absmax(da7281_handle_t* handle, uint8_t value);

/*
* @breif Get Actuator absolute maximum voltage
* @handle : Device handle struct
* @value : Default value is @DA7281_DEFAULT_ACTUATOR_ABSMAX in 23.4 mV steps
*/
int8_t da7281_get_actuator_absmax(da7281_handle_t *handle, uint8_t *value);

/*
* @breif Set Actuator maximum rated current
* @handle : Device handle struct
* @value : Default value is @DA7281_DEFAULT_ACTUATOR_ABSMAX in 23.4 mV steps
*/
int8_t da7281_set_actuator_imax(da7281_handle_t *handle, uint8_t value);

/*
* @breif Set V2I_FACTOR_H
* @handle : Device handle struct
* @value : Default value is @DA7281_DEFAULT_V2I_FACTOR_H
*/
int8_t da7281_set_v2i_factor_h(da7281_handle_t *handle, uint8_t value);

/*
* @breif Get V2I_FACTOR_H
* @handle : Device handle struct
* @value : Default value is @DA7281_DEFAULT_V2I_FACTOR_H
*/
int8_t da7281_get_v2i_factor_h(da7281_handle_t *handle, uint8_t *value);

/*
* @breif Set V2I_FACTOR_L
* @handle : Device handle struct
* @value : Default value is @DA7281_DEFAULT_V2I_FACTOR_L
*/
int8_t da7281_set_v2i_factor_l(da7281_handle_t *handle, uint8_t value);

/*
* @breif Get V2I_FACTOR_L
* @handle : Device handle struct
* @value : Default value is @DA7281_DEFAULT_V2I_FACTOR_L
*/
int8_t da7281_get_v2i_factor_l(da7281_handle_t *handle, uint8_t *value);

/*
* @breif Get Concatenated V2I_FACTOR
* @handle : Device handle struct
* @value : Value to be return
*/
int8_t da7281_set_v2i_factor(da7281_handle_t *handle, uint8_t *value);

/*
* @breif Get Impedance Z from V2I_FACTOR
* @handle : Device handle struct
* @value : Value to be return
*/
int8_t da7281_get_impedance(da7281_handle_t *handle, uint8_t *value);

/*
* @breif Set LRA_PER_H
* @handle : Device handle struct
* @value : Value to be return
*/
int8_t da7281_set_lra_per_h(da7281_handle_t *handle, uint8_t value);



