/*
* (C) HuXiaozhong 2018
* file_util.h 实现文件
*/
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include "file_util.h"

void init_code(Code_Template *code) {
    (*code).SECT_HEADER = "ORG 0000H\n\tLJMP MAIN\nORG 000BH\n\tLJMP TIMER_0\n\nORG 2000H\n\tMAIN:\n\tMOV TMOD, #01H\n\tMOV TH0, #0";
    (*code).SECT_HEADER_1 = "H\n\tMOV TL0, #0";
    (*code).SECT_HEADER_2 = "H\n\tSETB EA\n\tSETB ET0\n\tSETB TR0\n;Your main function is here.\n\n\n\n\tSJMP $\n\n";
    (*code).SECT_INT = "ORG 2100H\n\tTIMER_0:\n;Your interrupt function is here.\n\n\n\n";
    (*code).SECT_EXEC = "EXEC:RETI\nEND";
}

void write_code(string file_name, int THX, int TLX) {
    Code_Template code;
    init_code(&code);
    ofstream f(file_name);
    f << code.SECT_HEADER << THX << code.SECT_HEADER_1 << TLX << code.SECT_HEADER_2 << code.SECT_INT << code.SECT_EXEC;
    f.close();
}