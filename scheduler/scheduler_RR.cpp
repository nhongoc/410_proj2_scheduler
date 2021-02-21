/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Feb 17, 2020
 *      Author: Laura Slayton
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include "../includes/scheduler_RR.h"

using namespace std;

bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	if ((p.required_cpu_time - p.remaining_cpu_time) % time_slice == 0) {
		return true;
	}
	return Scheduler::time_to_switch_processes(tick_count, p);
}

//RR - preemptive - no sorting of ready_q needed.
void Scheduler_RR::sort() {}
