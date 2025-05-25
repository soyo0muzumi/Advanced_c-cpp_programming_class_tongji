#pragma once

/* 将所有const常量定义的头文件包含进来 */
#include "hanoi_const_value.h"
#include "cmd_console_tools.h"
#include "cmd_hdc_tools.h"

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

void menu();
void basic_solution(int n, char src, char tmp, char dst);
void basic_solution_saved(int n, char src, char tmp, char dst);
void show_inside_arr_row(int n, char src, char tmp, char dst);
void show_inside_arr_row_col(int n, char src, char tmp, char dst);
void print_3_cylinder();
void to_be_continued(const int pos_x = 0, const int pos_y = 22);
void print_3_cylinder_and_plates(int src, int n);
void initarr(int n, int source);
void print_3_cylinder_and_plates_and_move(int n, char src, char tmp, char dst);
void print_3_cylinder_and_plates_and_automove(int n, char src, char tmp, char dst);
void game(int n, char src, char tmp, char dst);
