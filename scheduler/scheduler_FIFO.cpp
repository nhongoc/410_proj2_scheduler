/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Feb 17, 2020
 *      Author: Laura Slayton
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

#include "../includes/scheduler_FIFO.h"

using namespace std;

bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p) {
	return Scheduler::time_to_switch_processes(tick_count, p);
}

//FIFO - not preemptive - no sorting needed
void Scheduler_FIFO::sort() {}
