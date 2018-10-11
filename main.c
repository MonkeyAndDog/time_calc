/*
* (C) HuXiaozhong 2018
*/
#include <stdio.h>
#include "timer.h"

int main() {
	Timer timer;
	init_timer(&timer);
	timer_output(&timer);
	return 0;
}