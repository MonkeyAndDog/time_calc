/*
* (C) HuXiaozhong 2018
*/
#include <stdio.h>

int main() {
	int fp;
	short need_time;
	int time;
	printf("输入晶振频率（MHZ）:");
	scanf("%d", &fp);
	printf("输入计时时间（ms）:");
	scanf("%hd", &need_time);
	time = 65536 - need_time;
	printf("TLX:%x\t", time & 0x0F);
	printf("THX:%x", (time & 0xF0) >> 4);
	return 0;
}