/*
* (C) HuXiaozhong 2018
* timer.h ��ʵ���ļ�
*/

#include <stdio.h>
#include "timer.h"

void init_timer(Timer *timer) {
	printf("���뾧��Ƶ�ʣ�MHZ��:");
	scanf("%f", &(*timer).fp);
	printf("�����ʱʱ�䣨ms��:");
	scanf("%hd", &(*timer).need_time);
}

void timer_output(Timer *timer) {
	(*timer).need_time *= 1000;
	(*timer).machine_time = 1.0 / (*timer).fp * 12;
	(*timer).need_time /= (*timer).machine_time;
	(*timer).time = 65536 - (*timer).need_time;
	printf("THX:%x\t", ((*timer).time & 0xFF00) >> 8);
	printf("TLX:%x\n", (*timer).time & 0xFF);
}