/*
* (C) HuXiaozhong 2018
* 程序模板读写工具集
* 参考程序：
* 
ORG 0000H
	LJMP MAIN
ORG 000BH
	LJMP TIMER_0
	
ORG 2000H
	MAIN:
	MOV TMOD, #01H
	MOV TH0, #3CH
	MOV TL0, #0B0H
	SETB EA
	SETB ET0
	SETB TR0
	MOV R0, #20H
	MOV A, #00H
	SJMP $

ORG 2100H
	TIMER_0:
	MOV TH0, #3CH
	MOV TL0, #0B0H
	DJNZ R0, EXEC
	MOV R0, #20H
	MOV P1, A
	CPL A

EXEC:RETI
END
*/
#include <stdio.h>
typedef struct {
	char *SECT_HEADER;
	char *SECT_HEADER_1;
	char *SECT_HEADER_2;
	char *SECT_INT;
	char *SECT_EXEC;
} Code_Template;

void init_code(Code_Template *code);
void write_code(char* file_name, int THX, int TLX);