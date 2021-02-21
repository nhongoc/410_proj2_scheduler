/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Feb 17, 2020
 *      Author: Laura Slayton
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include <algorithm>
#include "../includes/scheduler_SRTF.h"

using namespace std;

bool sort_by_cpu(PCB &p1, PCB &p2) {
	return p1.remaining_cpu_time > p2.remaining_cpu_time;
}

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	if (ready_q->front().remaining_cpu_time < p.remaining_cpu_time || ready_q->front().remaining_cpu_time < 0) {
		return true;
	}
	return Scheduler::time_to_switch_processes(tick_count, p);
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	vector<PCB> temp;

	for (unsigned int i = 0; i < ready_q->size(); i++) {
		temp.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(temp.begin(), temp.end(), sort_by_cpu);

	for (unsigned int i = 0; i < temp.size(); i++) {
		ready_q->push(temp.at(i));
	}
}
