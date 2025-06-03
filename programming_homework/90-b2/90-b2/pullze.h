
#pragma once
#include "cmd_console_tools.h"

// tools
void menu();
void option(char op, bool& isexit);
void build_matrix(int col, int* arr);
void clear(int* arr);
void calhint(int hint[][8], int* arr, int col, int& l, int& h);
void input(int& col);
void end();
void mouse_keyboards_tool(int col, int l, int h, int sidedif = 0);
bool check(int col, int* matrix, int* mymatrix, int sidedif, int hint[][8]);
void game_mouse_keyboards_tool(int col, int l, int h, int* mymatrix, int* matrix, int sidedif, int hint[][8]);
void draw_one_square(int x, int y, int color, const char str[3], int color2 = COLOR_BLACK);

// base
void show_basic_inner_arr(); // option A
void show_arr_and_hint(); // option B
void base_game_mode(); // option C

// console
void console_show_basic_inner_arr(); // option D
void console_show_arr_and_hint(); // option E
void console_show_arr_and_hint_mouse_moving(); // option F
void console_game_mode(); // option G

void _console_show_basic_inner_arr(); // option H
void _console_show_arr_and_hint(); // option I
void _console_show_arr_and_hint_mouse_moving(); // option J
void _console_game_mode(); //option K
