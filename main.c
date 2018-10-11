/*
* (C) HuXiaozhong 2018
*/
#include <stdio.h>
#include "timer.h"

void init_sys(void);

int main() {
	init_sys();
	Timer timer;
	while (1) {
		init_timer(&timer);
		timer_output(&timer);
	}
	return 0;
}

void init_sys(void) {
	printf("\tTime Calculator\n [ GNU General Public License v3.0] On Windows 2018 \n");
	printf(" The GNU General Public License is a free, copyleft license for software and other kinds of works.\n\n");
}