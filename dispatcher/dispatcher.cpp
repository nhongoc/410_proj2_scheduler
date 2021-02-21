/*
 * Dispatcher.cpp
 *
 *  Created on: Feb 17, 2020
 *      Author: Laura Slayton
 */

#include "../includes/dispatcher.h"

using namespace std;

//pull current process (if any) off CPU and return it
//if nothing on CPU returns an uninitialized PCB
PCB Dispatcher::get_from_CPU() {
	if (isValidJobOnCPU()) {
		return cpu->get_process_off_core();
	}
	return PCB();
}

//place the current process on the CPU for execution
void Dispatcher::put_on_CPU(PCB  &process) {
	if (!process.isEmpty() || !isValidJobOnCPU()) {
		cpu->put_process_on_core(process);
	}
}

//is CPU idle or working
bool Dispatcher::isValidJobOnCPU() {
	return !cpu->get_COPY_of_Current_Process().isEmpty();
}
