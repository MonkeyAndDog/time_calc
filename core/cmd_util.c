/*
* (C) HuXiaozhong 2018
* cmd_util.hÊµÏÖ
*/
#include "cmd_util.h"

void check_exit(char input) {
	if (input == 'q') {
		exit();
	}
}

int read_int(void) {
	int input;
	scanf("%d", &input);
	return input;
}

float read_float(void) {
	float input;
	scanf("%f", &input);
	return input;
}

short read_short(void) {
	short input;
	scanf("%hd", &input);
	return input;
}