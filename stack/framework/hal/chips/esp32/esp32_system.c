#include "hwsystem.h"

void hw_enter_lowpower_mode(uint8_t mode) {
    //TODO
}

uint64_t hw_get_unique_id(void) {
    //dummy ID return for now
    //TODO: get unique chip id from Efuse MAC (read IDF code?)

    return (uint64_t)(0xDEADBEEF);
}