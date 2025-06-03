

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

void draw_line(int col, int l) { // 画边框
	if (l) {
		for (int i = 0; i < l * 2 + 1; ++i)
			cout << "-";
	}
	cout << "+-+";
	for (int i = 0; i < col / 5; ++i) {
		cout << "-----------+";
	}
	cout << endl;
}


void _draw_hint(int col, int l, int h, int hint[][8]) {
	// 上边框
	for (int i = 0; i < l + 1; ++i) {
		cout << "--";
	}
	for (int j = 0; j < col / 5; ++j) {
		cout << "-+----------";
	}
	cout << "-+" << endl;
	
	for (int i = h - 1; i >= 0; --i) {
		for (int ij = 0; ij < l * 2 + 3; ++ij)
			cout << ' ';
		cout << "|";
		for (int ik = 0; ik < col/5; ++ik) {
			for (int ikl = 0; ikl < 5; ++ikl) {
				if (hint[ik*5 + ikl + 15][i] == 0)
					cout << "  ";
				else
					cout << setw(2) << hint[ik*5+ikl+15][i];
			}
			cout << " |";
		}
		cout << endl;
	}
	// 下边框
	for (int i = 0; i < l + 1; ++i) {
		cout << "--";
	}
	for (int j = 0; j < col / 5; ++j) {
		cout << "-+----------";
	}
	cout << "-+" << endl;
}

void _draw_matrix(int col, bool ifdrawhint, int l, bool game, int* matrix, int hint[][8]) {
	if (l) {
		for (int i = 0; i < l * 2 + 3; ++i)
			cout << ' ';
		cout << '|';
	}
	else
		cout << "| |";
	
	for (int i = 0; i < col / 5; ++i) {
		for (int k = 0; k < 5; ++k) {
			cout << setw(2) << (char)('a'+i*5+k);
		}
		cout << " |";
	}
	cout << endl;
	draw_line(col, l);
	for (int i = 0; i < col / 5; ++i) {
		for (int ik = 0; ik < 5; ++ik) {
			if (ifdrawhint) {
				for (int pos = 0; pos < l; ++pos) {
					if (hint[i*5+ik][pos] != 0)
						cout << setw(2) << hint[i*5+ik][pos];
					else
						cout << "  ";
				}
				cout << " ";
			}
			cout << "|" << (char)('A'+i*5+ik) << "|";
			for (int j = 0; j < col / 5; ++j) {
				for (int jk = 0; jk < 5; ++jk) {
					if (matrix[(i*5+ik)*col+j*5+jk] == 0)
						cout << "  ";
					else if (matrix[(i*5+ik)*col+j*5+jk] != 0 && game) {
						int x, y;
						cct_getxy(x, y);
						cct_showch(x + 1, y, 'O', COLOR_HYELLOW, COLOR_HBLUE);
						cct_setcolor(COLOR_BLACK, COLOR_WHITE);
					}
					else
						cout << " O";
				}
				cout << " |";
			}
			cout << endl;
		}
		draw_line(col, l);
	}
	cout << endl;
}


void __draw_matrix_game_z(int col, int l, int* matrix, int* mymatrix, int hint[][8]) {
	for (int i = 0; i < l * 2 + 3; ++i)
		cout << ' ';
	cout << '|';
	for (int i = 0; i < col / 5; ++i) {
		for (int k = 0; k < 5; ++k) {
			cout << setw(2) << (char)('a' + i * 5 + k);
		}
		cout << " |";
	}
	cout << endl;
	draw_line(col, l);
	for (int i = 0; i < col / 5; ++i) {
		for (int ik = 0; ik < 5; ++ik) {
			for (int pos = 0; pos < l; ++pos) {
				if (hint[i * 5 + ik][pos] != 0)
					cout << setw(2) << hint[i * 5 + ik][pos];
				else
					cout << "  ";
			}
			cout << " ";
			cout << "|" << (char)('A' + i * 5 + ik) << "|";
			for (int j = 0; j < col / 5; ++j) {
				for (int jk = 0; jk < 5; ++jk) {
					if (matrix[(i*5+ik)*col+j*5+jk] == 0 && mymatrix[(i*5+ik)*col+j*5+jk] == 0)
						cout << "  ";
					else if(matrix[(i*5+ik)*col+j*5+jk]==0 && mymatrix[(i*5+ik)*col+j*5+jk]!=0){
						int x, y;
						cct_getxy(x, y);
						cct_showch(x + 1, y, 'X', COLOR_HYELLOW, COLOR_HBLUE);
						cct_setcolor(COLOR_BLACK, COLOR_WHITE);
					}
					else if(matrix[(i*5+ik)*col+j*5+jk]==1 && mymatrix[(i*5+ik)*col+j*5+jk]==1){
						int x, y;
						cct_getxy(x, y);
						cct_showch(x + 1, y, 'O', COLOR_HYELLOW, COLOR_HBLUE);
						cct_setcolor(COLOR_BLACK, COLOR_WHITE);
					}
					else if(matrix[(i*5+ik)*col+j*5+jk]==1 && mymatrix[(i*5+ik)*col+j*5+jk]==0){
						cout << " O";
					}
				}
				cout << " |";
			}
			cout << endl;
		}
		draw_line(col, l);
	}
	cout << endl;
}



void show_basic_inner_arr() { // option A
	// 行号用大写，列号用小写
	int matrix[225] = { 0 };
	int hint[30][8] = { 0 }; // 0~14表示行，15~29表示列
	int col = 0;
	input(col);
	build_matrix(col, matrix);
	cout << "初始数组：" << endl;
	draw_line(col, 0);

	_draw_matrix(col, 0, 0, 0, matrix, hint);
	
	end();

	clear(matrix);
}


void show_arr_and_hint() { // option B
	int matrix[225] = {0};
	int hint[30][8] = {0}; // 0~14表示行，15~29表示列
	int col = 0;
	input(col);
	build_matrix(col, matrix);
	cout << "初始数组：" << endl;
	int l = 0, h = 0;

	calhint(hint, matrix, col, l, h);
	_draw_hint(col, l, h, hint);

	_draw_matrix(col, 1, l, 0, matrix, hint);

	end();

	clear(matrix);
}

void message() {
	cout << "命令形式：Aa=等价于图形游戏中鼠标左键选择Aa位(区分大小写)" << endl;
	cout << "             不需要支持图形界面的右键打叉，再次输入Aa相当于清除" << endl;
	cout << "          X/x = 退出(新行仅有X/x，不分大小写)" << endl;
	cout << "          Y/y = 提交(新行仅有Y/y，不分大小写)" << endl;	
	cout << "          Z/z = 作弊(新行仅有Z/z，不分大小写)" << endl;	
	cout << "          Ctrl+c 强制退出" << endl;	
	cout << "请输入 : ";	
}

void base_game_mode() {
	int col = 0;
	int matrix[225] = { 0 };
	int mymatrix[225] = { 0 };
	int hint[30][8] = { 0 }; // 0~14表示行，15~29表示列
	input(col);
	build_matrix(col, matrix);
	cout << "初始数组：" << endl;
	int l = 0, h = 0;

	calhint(hint, matrix, col, l, h);
	_draw_hint(col, l, h, hint);
	_draw_matrix(col, 1, l, 1, mymatrix, hint);
	bool inputz = false;
	while (1) {
		message();
		char operation[100] = {0};
		int i = 0;
		char ch = '\0';
		while (1) {
			ch = _getch();
			cout << ch;
			if (ch == '\n' || ch == '\r')
				break;
			operation[i++] = ch;
		}
		cout << endl;
		
		if(('A'<=operation[0]&&operation[0]<'A'+col)&&('a'<=operation[1]&&operation[1]<'a'+col)) {
			if (mymatrix[(operation[0] - 'A') * col + (operation[1] - 'a')] == 0)
				mymatrix[(operation[0] - 'A') * col + (operation[1] - 'a')] = 1;
			else if (mymatrix[(operation[0] - 'A') * col + (operation[1] - 'a')] == 1)
				mymatrix[(operation[0] - 'A') * col + (operation[1] - 'a')] = 0;
			cout << "输入" << operation << "后:" << endl;
			_draw_hint(col, l, h, hint);
			if (inputz) 
				__draw_matrix_game_z(col, l, matrix, mymatrix, hint);
			else
				_draw_matrix(col, 1, l, 1, mymatrix, hint);
			cout << endl << endl;
		}
		else if (strcmp(operation, "x") == 0 || strcmp(operation, "X") == 0) {
			break;
		}
		else if (strcmp(operation, "y") == 0 || strcmp(operation, "Y") == 0) {
			if (check(col, matrix, mymatrix,0,hint)) {
				cout << "提交成功，游戏结束" << endl;
				break;
			}
		}
		else if (strcmp(operation,"z") == 0 || strcmp(operation,"Z") == 0) {
			inputz = !inputz;
			cout << "输入Z/z后" << endl;
			_draw_hint(col, l, h, hint);
			__draw_matrix_game_z(col, l, matrix, mymatrix, hint);
		}
		else {
			cout << "输入错误" << endl;
		}
	}

	end();
}
