#include "hwtimer.h" //see this file for implementation details

error_t hw_timer_init(hwtimer_id_t timer_id, uint8_t frequency, 
                      timer_callback_t compare_callback, 
                      timer_callback_t overflow_callback) {

}

const hwtimer_info_t* hw_timer_get_info(hwtimer_id_t timer_id) {

}

hwtimer_tick_t hw_timer_getvalue(hwtimer_id_t timer_id) {

}

error_t hw_timer_schedule(hwtimer_id_t timer_id, hwtimer_tick_t tick ) {

}

error_t hw_timer_cancel(hwtimer_id_t timer_id) {

}

error_t hw_timer_counter_reset(hwtimer_id_t timer_id) {

}

bool hw_timer_is_overflow_pending(hwtimer_id_t id) {

}

bool hw_timer_is_interrupt_pending(hwtimer_id_t id) {
    
}