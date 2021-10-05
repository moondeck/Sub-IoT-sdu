#include "hwwatchdog.h"
#include "esp32_sfr.h"

void __watchdog_init(void) {
    //disable watchdog for now cuz thats how we roll B)

    TIMG0_Tx_WDTCONFIG0_REG &= ~(1 << 31);
    TIMG1_Tx_WDTCONFIG0_REG &= ~(1 << 31);

}