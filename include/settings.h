
#define D_OUT_ENABLE_FAN GPIO_NUM_25
#define PWM_OUT_RPWM GPIO_NUM_32
#define PWM_OUT_LPWM GPIO_NUM_33
#define LED_BUILTIN GPIO_NUM_2

#ifdef ENV_BOARD_LEFT
    #include "left/board_settings.h"
#else
    #ifdef ENV_BOARD_RIGHT
        #include "right/board_settings.h"
    #else
        #include "center/board_settings.h"
    #endif
#endif

#define OSC_LISTENER_PORT 55555
#define OSC_SEND_PORT 55555

// ESP_DoubleResetDetector
// Defines before include
#define ESP_DRD_USE_EEPROM      true
#define ESP_DRD_USE_SPIFFS      false
#define DOUBLERESETDETECTOR_DEBUG       false
#define DRD_TIMEOUT 10
// RTC Memory Address for the DoubleResetDetector to use
#define DRD_ADDRESS 0
