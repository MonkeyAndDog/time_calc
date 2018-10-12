/*
* (C) HuXiaozhong 2018
* timer.h ��ʵ���ļ�
*/

#include <stdio.h>
#include "timer.h"

void init_timer(Timer *timer) {
	printf("���뾧��Ƶ�ʣ�MHZ��\n>>> ");
	scanf("%f", &(*timer).fp);
	int limit_time = 65536 * 12 / (*timer).fp / 1000;
	printf("���ݾ���Ƶ�ʼ��㣬��ȡʱ�䷶Χ��0~%d(MS)\n", limit_time);
	printf("�����ʱʱ��(MS) \n>>> ");
	scanf("%hd", &(*timer).need_time);
}

void timer_output(Timer *timer) {
	(*timer).need_time *= 1000;
	(*timer).machine_time = 1.0 / (*timer).fp * 12;
	(*timer).need_time /= (*timer).machine_time;
	(*timer).time = 65536 - (*timer).need_time;
	printf("+------+-------+\n");
	printf("|THX   |TLX    |\n");
	printf("+------+-------+\n");
	printf("|%x    |%x     |\n", ((*timer).time & 0xFF00) >> 8, (*timer).time & 0xFF);
	printf("+------+-------+\n\n");
}