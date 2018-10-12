/*
* (C) HuXiaozhong 2018
* timer.h 的实现文件
*/

#include <stdio.h>
#include "timer.h"
#include "cmd_util.h"
#include "file_util.h"

void init_timer(Timer *timer) {
	printf("输入晶振频率（MHZ）\n>>> ");
	(*timer).fp = read_float();
	int limit_time = 65536 * 12 / (*timer).fp / 1000;
	printf("根据晶振频率计算，可取时间范围：0~%d(MS)\n", limit_time);
	printf("输入计时时间(MS) \n>>> ");
	(*timer).need_time = read_int();
}

void timer_output(Timer *timer) {
	(*timer).need_time *= 1000;
	(*timer).machine_time = 1.0 / (*timer).fp * 12;
	(*timer).need_time /= (*timer).machine_time;
	(*timer).time = 65536 - (*timer).need_time;
	int THX = (*timer).time >> 8;
	int TLX = (*timer).time & 0xFF;
	printf("+------+-------+\n");
	printf("|THX   |TLX    |\n");
	printf("+------+-------+\n");
	printf("|%x    |%x     |\n", THX, TLX);
	printf("+------+-------+\n");
	write_code("code.asm", THX, TLX);
	printf("程序已在当前目录下生成。\n\n");
}