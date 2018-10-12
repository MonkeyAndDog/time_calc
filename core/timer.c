/*
* (C) HuXiaozhong 2018
* timer.h ��ʵ���ļ�
*/

#include <stdio.h>
#include "timer.h"
#include "cmd_util.h"
#include "file_util.h"

void init_timer(Timer *timer) {
	printf("���뾧��Ƶ�ʣ�MHZ��\n>>> ");
	(*timer).fp = read_float();
	int limit_time = 65536 * 12 / (*timer).fp / 1000;
	printf("���ݾ���Ƶ�ʼ��㣬��ȡʱ�䷶Χ��0~%d(MS)\n", limit_time);
	printf("�����ʱʱ��(MS) \n>>> ");
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
	printf("�������ڵ�ǰĿ¼�����ɡ�\n\n");
}