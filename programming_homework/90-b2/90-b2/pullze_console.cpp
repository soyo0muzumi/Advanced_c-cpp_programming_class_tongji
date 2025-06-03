

#include <iostream>
#include <iomanip>
#include "pullze.h"
#include <cstdio>
#include <conio.h>

using namespace std;

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void console_draw_line_without_seperateline(int col, int l, int op, int sidedif, int op2 = 0) {
	if (op2 == 0) op2 = op;
	const char strbegin[][4] = { "╔","╠","╚" };
	const char strend[][4] = { "╗","╣","╝" };
	const char strlink[][4] = { "╦","╬","╩" };
	int x, y;
	cct_getxy(x, y);
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	if (!l) {
		cout << "  "; x += 2;
		cct_showstr(x, y, strbegin[op - 1], COLOR_HWHITE, COLOR_BLACK); x += 1 + sidedif;
	}
	else {
		cct_showstr(0, y, strbegin[op-1], COLOR_HWHITE, COLOR_BLACK); 
		x+=1+sidedif;
		for (int i = 0; i < l; ++i) {
			cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK);
			x += 2;
		}
		cct_showstr(x, y, strlink[op - 1], COLOR_HWHITE, COLOR_BLACK, sidedif);
		x += sidedif * 2;
		cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 2); x += 4;
		x -= (1 + sidedif-(l>0))*2;
		cct_showstr(x, y, strlink[op2 - 1], COLOR_HWHITE, COLOR_BLACK, sidedif);
		//op2特殊处理
		x += 2;
	}
	for (int i = 0; i < col - sidedif; ++i) {
		cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1+sidedif*2);
		x += 2+sidedif*4;
		cct_showstr(x, y, strlink[op-1], COLOR_HWHITE, COLOR_BLACK, sidedif);
		x += sidedif * 2;
	}
	cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1 + sidedif * 2);
	x += 2 + sidedif * 4;
	x-=1-sidedif;
	cct_showstr(x, y, strend[op2-1], COLOR_HWHITE, COLOR_BLACK); x+=1+sidedif;
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cct_showch(x, y, '\n');
}


void console_draw_line_slversion(int startX, int length, int op) {
	const char strbegin[][4] = { "╔","╠","╚" };
	const char strend[][4] = { "╗","╣","╝" };
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	int x, y;
	cct_getxy(x, y);
	x = startX;
	cct_gotoxy(x, y);
	cct_showstr(x, y, strbegin[op - 1], COLOR_HWHITE, COLOR_BLACK); x++;
	cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, length+1); x += length*2+1;
	cct_showstr(x, y, strend[op - 1], COLOR_HWHITE, COLOR_BLACK); x++;
	cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK); x++;
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cct_showch(x, y, '\n');
}

void print_a_to_col(int col, int l, int sizedif = 0) {
	int x, y;
	int bcolor, fcolor;
	cct_getxy(x, y);
	if (l == 0) {
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cct_getcolor(bcolor, fcolor);
		cout << "    ";
		if (sizedif)
			cout << " ";
		x += 4+sizedif;
	}
	else {
		x = 2 * (l + 3);
		cct_gotoxy(x, y); 
		cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK); x += 2;
		cct_getcolor(bcolor, fcolor);
	}
	for (int i = 0; i < col; ++i) {
		cct_showch(x, y, ' ', bcolor, fcolor, 1+(l>0)-(sizedif==0)); x+=1+(l>0)-(sizedif==0);
		cct_showch(x++, y, (char)('a' + i), bcolor, fcolor);
		cct_showch(x, y, ' ', bcolor, fcolor, sizedif*(6-(l>0)));
		x += sizedif * (6-(l>0));
	}
	if (l) {
		x -= 2*(sizedif);
		cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK); x += 2;
	}
		
	cout << endl;
}

void console_draw_matrix(int col, int* matrix, int hint[][8], int l, bool sidedif) {
	print_a_to_col(col, l, sidedif);
	if (!l)
		console_draw_line_without_seperateline(col, 0, 1, sidedif);
	else
		console_draw_line_slversion(0, col + l + 3, 1);
	int x, y;
	int bcolor, fcolor;
	cct_getcolor(bcolor, fcolor);
	for (int i = 0; i < col / 5; ++i) {
		for (int ik = 0; ik < 5; ++ik) {
			cct_getxy(x, y);
			if(l && !sidedif)
				cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK), x += 2;
			for (int pos = 0; pos < l; ++pos) {
				cct_getcolor(bcolor, fcolor);
				if (hint[i * 5 + ik][pos] != 0)
					cct_showint(x, y, hint[i * 5 + ik][pos], bcolor, fcolor),
					cout << " ",
					x += 2;
				else
					cout << "  ", x += 2;
			}
			if (l) {
				cct_getxy(x, y);
				cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK); x += 2;
				cct_gotoxy(x, y);
				cout << " ";
				cout << (char)('A' + i * 5 + ik);
			}
			else {
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
				cout << (char)('A' + i * 5 + ik) << " ";
			}
			cct_getxy(x, y);
			cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK); x+=2;
			for (int j = 0; j < col / 5; ++j) {
				for (int jk = 0; jk < 5; ++jk) {
					if (matrix[(i * 5 + ik) * col + j * 5 + jk] == 0) {
						cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK, 2); x += 2;
					}
					else if (matrix[(i * 5 + ik) * col + j * 5 + jk] != 0) {
						cct_getxy(x, y);
						cct_showstr(x, y, "〇", COLOR_HBLUE, COLOR_BLACK);
						x += 2;
					}
				}
			}
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);
			cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK);
			cout << endl;
		}
	}
	if (!l) {
		console_draw_line_without_seperateline(col, 0, 3, sidedif);
		cout << endl;
	}
	else
		console_draw_line_slversion(0, col + l + 3, 3);
}

void draw_one_line_square(int X, int Y, int col) {
	int x = X, y = Y;
	for (int i = 0; i < 3; ++i) {
		cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK); x += 2;
		for (int j = 0; j < col; ++j) {
			cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK, 6); x += 6;
			cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK); x += 2;
		}
		
		cout << endl; y++;
		x = X;
	}
}



void draw_mid_line(int l, int col) {
	int x, y; cct_getxy(x, y);
	cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK), x += 2;
	for (int i = 0; i < l; ++i) {
		cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK, 2);
		x += 2;
	}
	cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK), x += 2;
	cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK, 2); x += 2;
	cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK), x += 2;
	for (int i = 0; i < col; ++i) {
		cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK, 6);
		x += 6;
		cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK), x += 2;
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cct_showch(x, y, '\n');
}

void _console_draw_matrix(int col, int* matrix, int hint[][8], int l,  bool sidedif, int h = 0) {
	print_a_to_col(col, l, sidedif);
	if (!l)
		console_draw_line_without_seperateline(col, 0, 1, sidedif);
	else
		console_draw_line_without_seperateline(col, l, 1, sidedif, 2);
	int x, y;
	cct_getxy(x, y);
	int bcolor, fcolor;
	for (int i = 1; i <= col; ++i) {
		if (l)
			draw_mid_line(l, col),
			cct_getxy(x, y);
			cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK), x += 2;
		for (int pos = 0; pos < l; ++pos) {
			cct_getcolor(bcolor, fcolor);
			if (hint[i-1][pos] != 0)
				cct_showint(x, y, hint[i-1][pos], bcolor, fcolor),
				cout << " ",
				x += 2;
			else
				cout << "  ", x += 2;
		}
		if (!l)
			cct_showch(0, i * 4, 'A' + i - 1, COLOR_BLACK, COLOR_HWHITE);
		else
			cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK), x += 2,
			cct_showch(x++,y, ' ', COLOR_HWHITE, COLOR_BLACK),
			cct_showch(x++, y, 'A'+i-1, COLOR_HWHITE, COLOR_BLACK),
			cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK), x += 2;
		if (l)
			draw_one_line_square(x - 2, y - 1, col),
			cct_gotoxy(0, y + 1),
			draw_mid_line(l, col);
		else
			draw_one_line_square(2, i*4-1, col);
		console_draw_line_without_seperateline(col, l, 2, sidedif);
	}
	cct_getxy(x, y);
	cct_gotoxy(x, y - 1);
	console_draw_line_without_seperateline(col, l, 3, sidedif);

	for (int i = 0; i < col; ++i) {
		for (int ik = 0; ik < col; ++ik) {
			if (matrix[i * col + ik] == 1) {
				if (!l)
					draw_one_square(4 + ik * 8, i * 4 + 3, COLOR_HBLUE, "〇");
				else
					draw_one_square(2*l+8+ik*8, i*4+h+5, COLOR_HBLUE, "〇");
			}
		}
	}

	/*if (!l)
		console_draw_line_without_seperateline(col, 0, 1, sidedif);
	else
		console_draw_line_slversion(0, col*3 + l + 3, 1);*/
}


void console_show_basic_inner_arr() { // option D
	int col = 0;
	input(col); 
	int matrix[225] = { 0 };
	int hint[30][8] = { 0 }; // 0~14表示行，15~29表示列
	build_matrix(col, matrix);
	cct_setconsoleborder(col*2+7, 23);
	int systemfontsize = cct_getfontinfo();
	cct_setfontsize("新宋体", 36);
	cct_cls();

	cout << endl;

	console_draw_matrix(col, matrix, hint, 0, 0);

	end();
}

void console_draw_hint(int l, int h, int col, int hint[][8]) {
	// 上边框
	console_draw_line_slversion(2*(l+3), col, 1);
	int x, y;
	for (int i = h - 1; i >= 0; --i) {
		cct_getxy(x, y);
		x = 2 * (l + 3);
		cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK); x += 2;
		for (int ik = 0; ik < col / 5; ++ik) {
			for (int ikl = 0; ikl < 5; ++ikl) {
				if (hint[ik * 5 + ikl + 15][i] == 0)
					cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK,2), x+=2;
				else {
					if(hint[ik * 5 + ikl + 15][i]/10 == 0)
						cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK), x++;
					else {
						cct_showch(x, y, '1', COLOR_HWHITE, COLOR_BLACK), x++;
					}
					cct_showch(x,y,(char)(hint[ik*5+ikl+15][i]%10+'0'), COLOR_HWHITE, COLOR_BLACK), x++;
				}
			}
		}
		cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK); x += 2;
		cout << endl;
	}
	// 下边框
	console_draw_line_slversion(2*(l+3), col, 2);
}

void _console_draw_hint(int l, int h, int col, int hint[][8]) {
	// 上边框
	console_draw_line_slversion(2 * (l + 3), col*4-1, 1);
	int x, y;
	for (int i = h - 1; i >= 0; --i) {
		cct_getxy(x, y);
		x = 2 * (l + 3);
		cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK); x += 2;
		cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK), x++;
		for (int ik = 0; ik < col / 5; ++ik) {
			for (int ikl = 0; ikl < 5; ++ikl) {
				if (hint[ik * 5 + ikl + 15][i] == 0)
					cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK, 2), x += 2;
				else {
					if (hint[ik * 5 + ikl + 15][i] / 10 == 0)
						cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK), x++;
					else {
						cct_showch(x, y, '1', COLOR_HWHITE, COLOR_BLACK), x++;
					}
					cct_showch(x, y, (char)(hint[ik * 5 + ikl + 15][i] % 10 + '0'), COLOR_HWHITE, COLOR_BLACK), x++;
				}
				cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK, 6), x+=6;
			}
		}
		x -= 3;
		cct_showch(x, y, ' ', COLOR_BLACK, COLOR_HWHITE, 6);

		cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK); x += 2;
		cout << endl;
	}
	// 下边框
	console_draw_line_slversion(2 * (l + 3), col*4-1, 2);
}

void adjust(int x, int y, int col, int l) {
	cct_showstr(2 * (l + 1), y + 1, "╦", COLOR_HWHITE, COLOR_BLACK);
	cct_showstr(2 * (l + 2), y + 1, "═", COLOR_HWHITE, COLOR_BLACK);
	cct_showstr(2 * (l + 3), y + 1, "╬", COLOR_HWHITE, COLOR_BLACK);
	for (int i = 0; i < col; ++i) {
		cct_showstr(2 * (l + 4 + i), y + 1, "═", COLOR_HWHITE, COLOR_BLACK);
	}
	cct_showstr(2 * (l + col + 4), y + 1, "╣", COLOR_HWHITE, COLOR_BLACK);

	cct_getxy(x, y);
	cct_showstr(2 * (l + 1), y + col + 1, "╩", COLOR_HWHITE, COLOR_BLACK);
	cct_showstr(2 * (l + 2), y + col + 1, "═", COLOR_HWHITE, COLOR_BLACK);
	cct_showstr(2 * (l + 3), y + col + 1, "╩", COLOR_HWHITE, COLOR_BLACK);
	for (int i = 0; i < col; ++i) {
		cct_showstr(2 * (l + 4 + i), y + col + 1, "═", COLOR_HWHITE, COLOR_BLACK);
	}
	cct_showstr(2 * (l + col + 4), y + col + 1, "╝", COLOR_HWHITE, COLOR_BLACK);

}

void console_show_arr_and_hint() { // option E
	int matrix[225] = { 0 };
	int hint[30][8] = { 0 }; // 0~14表示行，15~29表示列
	int col = 0;
	input(col);
	build_matrix(col, matrix);
	int l = 0, h = 0;

	calhint(hint, matrix, col, l, h);
	cct_setconsoleborder(67, 30);
	int systemfontsize = cct_getfontinfo();
	cct_setfontsize("新宋体", 36);
	cct_cls();

	cout << endl;

	console_draw_hint(l, h, col, hint);

	int x, y;
	cct_getxy(x, y);

	console_draw_matrix(col, matrix, hint, l, 0);
	adjust(x, y, col, l);
	cct_setcolor(COLOR_BLACK, COLOR_HWHITE);

	end();
}

void console_show_arr_and_hint_mouse_moving() {
	int matrix[225] = { 0 };
	int hint[30][8] = { 0 }; // 0~14表示行，15~29表示列
	int col = 0;
	input(col);
	build_matrix(col, matrix);
	int l = 0, h = 0;

	calhint(hint, matrix, col, l, h);
	cct_setconsoleborder(67, 30);
	int systemfontsize = cct_getfontinfo();
	cct_setfontsize("新宋体", 36);
	cct_cls();

	cout << "测试键盘/鼠标左键/右键，回车退出" << endl;

	console_draw_hint(l, h, col, hint);

	int x, y;
	cct_getxy(x, y);

	console_draw_matrix(col, matrix, hint, l, 0);
	adjust(x, y, col, l);
	cct_setcolor(COLOR_BLACK, COLOR_HWHITE);

	cct_enable_mouse();

	mouse_keyboards_tool(col, l, h);

	end();
}


void console_game_mode() {
	int matrix[225] = { 0 };
	int mymatrix[225] = { 0 };
	int hint[30][8] = { 0 }; // 0~14表示行，15~29表示列
	int col = 0;
	input(col);
	build_matrix(col, matrix);
	int l = 0, h = 0;

	calhint(hint, matrix, col, l, h);
	cct_setconsoleborder(67, 30);
	int systemfontsize = cct_getfontinfo();
	cct_setfontsize("新宋体", 36);
	cct_cls();

	cout << "左键选〇/右键选×, Y/y提交, Z/z作弊, Q/q结束" << endl;

	console_draw_hint(l, h, col, hint);

	int x, y;
	cct_getxy(x, y);

	console_draw_matrix(col, mymatrix, hint, l, 0);
	adjust(x, y, col, l);
	cct_setcolor(COLOR_BLACK, COLOR_HWHITE);

	cct_enable_mouse();

	game_mouse_keyboards_tool(col, l, h, mymatrix, matrix, 0, hint);

	end();
}


void _console_show_basic_inner_arr() { // option H
	int col = 0;
	input(col);
	int matrix[225] = { 0 };
	int hint[30][8] = { 0 }; // 0~14表示行，15~29表示列
	build_matrix(col, matrix);
	cct_setconsoleborder(col * 8 + 5 + 2, 70);
	int systemfontsize = cct_getfontinfo();
	int font = 24 - col / 5 * 4;
	if (col == 5) font += 4;
	cct_setfontsize("新宋体", font);
	cct_cls();

	cout << endl;

	_console_draw_matrix(col, matrix, hint, 0, 1);
	cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
	cout << "\n\n";
	end();
}


void _console_show_arr_and_hint() {
	int col = 0;
	input(col);
	int matrix[225] = { 0 };
	int hint[30][8] = { 0 }; // 0~14表示行，15~29表示列
	build_matrix(col, matrix);
	cct_setconsoleborder(150, 70);
	int systemfontsize = cct_getfontinfo();
	int font = 24 - col / 5 * 4;
	if (col == 5) font += 4;
	cct_setfontsize("新宋体", font);
	cct_cls();
	int l = 0, h = 0;
	calhint(hint, matrix, col, l, h);

	cout << endl;

	_console_draw_hint(l, h, col, hint);
	_console_draw_matrix(col, matrix, hint, l, 1, h);
	cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
	cout << "\n\n";
	end();
}



void _console_show_arr_and_hint_mouse_moving() {
	int col = 0;
	input(col);
	int matrix[225] = { 0 };
	int hint[30][8] = { 0 }; // 0~14表示行，15~29表示列
	build_matrix(col, matrix);
	cct_setconsoleborder(150, 70);
	int systemfontsize = cct_getfontinfo();
	int font = 24 - col / 5 * 4;
	if (col == 5) font += 4;
	cct_setfontsize("新宋体", font);
	cct_cls();
	int l = 0, h = 0;
	calhint(hint, matrix, col, l, h);

	cout << "测试键盘/鼠标左键/右键，回车退出" << endl;

	_console_draw_hint(l, h, col, hint);
	_console_draw_matrix(col, matrix, hint, l, 1, h);
	cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
	cout << "\n\n";

	mouse_keyboards_tool(col, l, h, 1);

	end();
}


void _console_game_mode() {
	int col = 0;
	input(col);
	int matrix[225] = { 0 };
	int mymatrix[225] = { 0 };
	int hint[30][8] = { 0 }; // 0~14表示行，15~29表示列
	build_matrix(col, matrix);
	cct_setconsoleborder(150, 70);
	int systemfontsize = cct_getfontinfo();
	int font = 24 - col / 5 * 4;
	if (col == 5) font += 4;
	cct_setfontsize("新宋体", font);
	cct_cls();
	int l = 0, h = 0;
	calhint(hint, matrix, col, l, h);

	cout << "左键选〇/右键选×, Y/y提交 , Z/z作弊, Q/q结束" << endl;

	_console_draw_hint(l, h, col, hint);
	_console_draw_matrix(col, mymatrix, hint, l, 1, h);
	cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
	cout << "\n\n";

	game_mouse_keyboards_tool(col, l, h, mymatrix, matrix, 1, hint);

	end();
}
