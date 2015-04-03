/* * OSS-7 - An opensource implementation of the DASH7 Alliance Protocol for ultra
 * lowpower wireless sensor communication
 *
 * Copyright 2015 University of Antwerp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * HalModule.h
 *
 *  Created on: 12 Feb 2015
 *      Author: guust
 */

#ifndef _HAL_HALMODULE_H_
#define _HAL_HALMODULE_H_
#include "errors.h"
#include "hwtimer.h"
#include "scheduler.h"
#include "timer.h"

#include "HalModuleBase.h"
#include <map>
class HalModule: public HalModuleBase
{
	protected:
		virtual void startup();
		virtual void finishSpecific();
		virtual void fromRadio(RadioPacket* packet);
		virtual void handleRadioControlMessage(RadioControlMessage* msg);
		virtual void timerFiredCallback(int index);
	public:
		HalModule();
		virtual ~HalModule();

		static HalModule* getActiveModule();

		//hwtimer functions
		error_t create_hwtimer(hwtimer_id_t id, simtime_t tick_length, timer_callback_t compare_callback, timer_callback_t overflow_callback);
		hwtimer_tick_t hw_timer_getvalue(hwtimer_id_t timer_id);
		error_t hw_timer_schedule(hwtimer_id_t timer_id, hwtimer_tick_t tick );
		error_t hw_timer_cancel(hwtimer_id_t timer_id);
		error_t hw_timer_counter_reset(hwtimer_id_t timer_id);

		//framework scheduler functions
		void scheduler_init();
		error_t sched_register_task(task_t task);
		error_t sched_post_task_prio(task_t task, uint8_t priority);
		error_t sched_cancel_task(task_t task);
		bool sched_is_scheduled(task_t task);

		//framework timer functions
		void timer_init();
		timer_tick_t timer_get_counter_value();
		error_t timer_post_task_prio(task_t task, timer_tick_t time, uint8_t priority);
		error_t timer_cancel_task(task_t task);

		//log support functions
		inline ostream& get_log_stream() { return trace();}

		//hwradio functions

		error_t hw_radio_init(uint8_t* initial_rx_buffer, rx_packet_callback_t callback);
		error_t hw_radio_setenabled(bool enabled);
		error_t hw_radio_send_packet(uint8_t* buffer, uint8_t length);

		inline double get_node_time() { return getClock().dbl();}
		inline double get_real_time() { return simTime().dbl();}

	private:

		simtime_t interTaskDelay;
		simtime_t taskExecutionTime;
		uint8_t cur_task_priority;
		bool scheduler_inited;

		simtime_t frtimer_tick_length;
		simtime_t frtimer_reset_offset;
		bool frtimer_inited;

		bool isContextValid();
		struct hw_timer_info
		{
			timer_callback_t compare_callback;
			timer_callback_t overflow_callback;
			simtime_t reset_offset;
			simtime_t tick_length;
		};
		hwtimer_tick_t get_hw_timer_tick(hw_timer_info const& info);
		std::map<hwtimer_id_t,hw_timer_info> hwtimers;

		struct task_info
		{
			uint8_t priority;
			std::list<task_t>::iterator pos;
		};
		std::vector<std::list<task_t> > task_queue;
		std::map<task_t, task_info> tasks;

		struct frtimer_info
		{
			simtime_t fire_time;
			task_t task;
			uint8_t priority;
			frtimer_info(simtime_t const& fire_time, task_t const& task, uint8_t priority);
		};
		std::set<frtimer_info> frtimers;
		std::set<task_t> frtimer_tasks;
		void reset_frtimer();
		void configure_next_frtimer();
		friend bool operator<(frtimer_info const& a, frtimer_info const& b);

		uint8_t* radio_buffer;
		bool radio_enabled;
		rx_packet_callback_t radio_callback;


};

bool operator<(HalModule::frtimer_info const& a, HalModule::frtimer_info const& b);

#endif /* _HAL_HALMODULE_H_ */

