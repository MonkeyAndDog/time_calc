/*
* (C) HuXiaozhong 2018
*/
#include <stdio.h>

int main() {
	int fp;
	short need_time;
	int time;
	printf("���뾧��Ƶ�ʣ�MHZ��:");
	scanf("%d", &fp);
	printf("�����ʱʱ�䣨ms��:");
	scanf("%hd", &need_time);
	time = 65536 - need_time;
	printf("TLX:%x\t", time & 0x0F);
	printf("THX:%x", (time & 0xF0) >> 4);
	return 0;
}