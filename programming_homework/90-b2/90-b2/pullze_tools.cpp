
#include <iostream>
#include <time.h>
#include "pullze.h"
using namespace std;


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

void menu() {
	cout << "---------------------------------------------------------\n";
	cout << "A.内部数组，原样输出\n";
	cout << "B.内部数组，生成提示行列并输出" << endl;
	cout << "C.内部数组，游戏版" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "D.n * n的框架(无分隔线)，原样输出" << endl;
	cout << "E.n * n的框架(无分隔线)，含提示行列" << endl;
	cout << "F.n * n的框架(无分隔线)，显示初始状态，鼠标移动可显示坐标" << endl;
	cout << "G.cmd图形界面完整版(无分隔线)" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "H.n * n的框架(有分隔线)，原样输出" << endl;
	cout << "I.n * n的框架(有分隔线)，含提示行列" << endl;
	cout << "J.n * n的框架(有分隔线)，显示初始状态，鼠标移动可显示坐标" << endl;
	cout << "K.cmd图形界面完整版(有分隔线)" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Q.退出" << endl;
	cout << "-------------------------------------------------------- -" << endl;
	cout << "[请选择:]";
}

void option(char op, bool& isexit) {
	cct_cls();
	switch (op)
	{
	case 'A':
		show_basic_inner_arr();
		break;
	case 'B':
		show_arr_and_hint();
		break;
	case 'C':
		base_game_mode();
		break;
	case 'D':
		console_show_basic_inner_arr();
		break;
	case 'E':
		console_show_arr_and_hint();
		break;
	case 'F':
		console_show_arr_and_hint_mouse_moving();
		break;
	case 'G' :
		console_game_mode();
		break;
	case 'H':
		_console_show_basic_inner_arr();
		break;
	case 'I':
		_console_show_arr_and_hint();
		break;
	case 'J':
		_console_show_arr_and_hint_mouse_moving();
		break;
	case 'K':
		_console_game_mode();
		break;
	case 'Q':
		isexit = true;
		break;
	default:
		break;
	}
}


void build_matrix(int col, int* arr) {
	srand((unsigned int)time(NULL));
	int count = col * col / 2;
	if (col * col % 2)
		count++;
	int i = 0;
	while (i < count) {
		int pos = rand() % (col * col);
		if (arr[pos] == 0) {
			arr[pos] = 1;
			i++;
		}
	}
}

void clear(int* arr) {
	for (int i = 0; i < 225; ++i) {
		arr[i] = 0;
	}
}

void calhint(int hint[][8], int* arr, int col, int& l, int& h) {
	// 计算行提示
	for (int k = 0; k < col; ++k) {
		int ki = 0; int curpos = 0;
		while (ki < col) {
			while (arr[k * col + ki] == 0 && ki < col) {
				ki++;
			}
			while (arr[k * col + ki] == 1 && ki < col) {
				hint[k][curpos]++;
				ki++;
				if (ki == col) curpos++;
			}
			if (arr[k * col + ki] == 0 && ki < col)
				curpos++;
		}
		l = max(l, curpos);
	}

	// 计算列提示 // 从下到上算
	for (int k = 15; k < col + 15; ++k) {
		int ki = col - 1; int curpos = 0;
		while (ki >= 0) {
			while (arr[ki * col + k - 15] == 0 && ki >= 0) {
				ki--;
			}
			while (arr[ki * col + k - 15] == 1 && ki >= 0) {
				hint[k][curpos]++;
				ki--;
				if (ki == -1) curpos++;
			}
			if (arr[ki * col + k - 15] == 0 && ki >= 0)
				curpos++;
		}
		h = max(h, curpos);
	}
}

void input(int& col) {
	while (1) {
		cout << "请输入区域大小(5/10/15) ： ";
		cin >> col;
		if (col == 5 || col == 10 || col == 15)
			break;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

void end() {
	int x, y;
	cct_getxy(x, y);

	char End[100];
	while (1) {
		cct_gotoxy(x, y);
		cout << "本小题结束，请输入End继续...    ";
		int x1, y1;
		cct_getxy(x1, y1);
		cct_gotoxy(x1 - 4, y1);
		cin >> End;
		if (!strcmp(End, "End") || !strcmp(End, "end"))
			break;
		else {
			cout << "输入错误，请重新输入";
		}
	}
}


bool judgeposition(int x, int y, int col, int l, int h, int sidedif, int& i, int& j) {
	char s1[] = { "ABCDEFGHIJKLMNO" };
	char s2[] = { "aabbccddeeffgghhiijjkkllmmnnoo" };
	if (sidedif == 0) {
		if ((x > 2 * (l + col + 4) - 1 || x < 2 * (l + 4)) || (y < h + 5 || y > h + col + 6)) {
			cout << "[当前光标] 位置非法";
			return false;
		}
		else {
			cout << "[当前光标] " << s1[(y - h - 5)] << "行" << s2[x - 2 * (l + 4)] << "列    " << endl;
			return true;
		}
	}
	else {
		for (i = 0; i < col; ++i) {
			for (j = 0; j < col; ++j) {
				if ((x < 2*(l+4)-1+6+i*8 && x >= 2*(l+4)+i*8) 
					&& (y >= h+5+j*4 && y < h+j*4+5+3)) {
					cout << "[当前光标] " << s1[j] << "行" << s2[i*2] << "列    " << endl;
					return true;
				}
			}
		}
		cout << "[当前光标] 位置非法";
		return false;
	}
}

void mouse_keyboards_tool(int col, int l, int h, int sidedif) {
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;

	cct_enable_mouse();

	/* 打印初始光标位置[0,0] */
	cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
	//		cout << "[当前鼠标位置] X:0  Y:0"; //打印初始鼠标位置

	while (loop) {
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT) {

			switch (maction) {
			case MOUSE_ONLY_MOVED:
				cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);
				int i, j;
				judgeposition(X, Y, col, l, h, sidedif,i,j);
				break;
			case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
				cout << "读到左键" << endl;
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:			//按下右键
				cout << "读到右键" << endl;
				break;
			} //end of switch(maction)
		} //end of if (CCT_MOUSE_EVENT)
		else if (ret == CCT_KEYBOARD_EVENT) {
			/* 转到第9行进行打印 */
			cct_gotoxy(12, col + h + 8 + sidedif *5*col/2);

			switch (keycode1) {
			case '\n':
				loop = 0;
				cout << "[读到回车键]";
				break;
			case '\r':
				loop = 0;
				cout << "[读到回车键]";
				break;
			case 224:
				switch (keycode2) {
				case KB_ARROW_UP:
					cout << "[读到上箭头]";
					break;
				case KB_ARROW_DOWN:
					cout << "[读到下箭头]";
					break;
				case KB_ARROW_LEFT:
					cout << "[读到左箭头]";
					break;
				case KB_ARROW_RIGHT:
					cout << "[读到右箭头]";
					break;
				}
				break;
			default:	//其他键直接打印ASCII值
				cout << "[读到键码] :" << keycode1 << '/' << keycode2 << endl;
				break;
			}//end of swicth(keycode1)
		}//end of else if(ret == CCT_KEYBOARD_EVENT）
	} //end of while(1)

	cct_disable_mouse();	//禁用鼠标
	cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标
}

bool check(int col, int* matrix, int* mymatrix, int sidedif, int hint[][8]) {
	int myhint[30][8] = { 0 };
	int l, h;
	calhint(myhint, mymatrix, col, l, h);
	bool ishintequal = true;
	for (int i = 0; i < 30; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (myhint[i][j] != hint[i][j]) {
				ishintequal = false; 
				break;
			}
		}
		if (!ishintequal) break;
	}
	if (ishintequal) return true;

	for (int i = 0; i < col * col; ++i) {
		if (matrix[i] != mymatrix[i]) {
			cout << "[" << (char)('A' + i / col) << "]" << "行" << "[" << (char)('a' + i % col) << "]" << "列不符合要求";
			return false;
		}
	}

	return true;
}

void draw_single(int X, int Y, int col, int l, int h, int* mymatrix, int* _mymatrix, int op, int color) {
	char s0[][3] = { "〇","×" };
	char s1[] = { "ABCDEFGHIJKLMNO" };
	char s2[] = { "aabbccddeeffgghhiijjkkllmmnnoo" };
	int pos = (s1[(Y - h - 5)] - 'A') * col + s2[X - 2 * (l + 4)] - 'a';
	int posy = pos / col, posx = pos % col;
	if (op) {
		_mymatrix[pos] == 0 ? _mymatrix[pos] = 1 : _mymatrix[pos] = 0;
		mymatrix[pos] = 0;
		if (_mymatrix[pos] == 1)
			cct_showstr(posx * 2 + 2 * (l + 4), posy + h + 5, s0[op], color, COLOR_BLACK);
		else if (_mymatrix[pos] == 0)
			cct_showch(posx * 2 + 2 * (l + 4), posy + h + 5, ' ', COLOR_HWHITE, COLOR_BLACK, 2);
	}
	else {
		mymatrix[pos] == 0 ? mymatrix[pos] = 1 : mymatrix[pos] = 0;
		_mymatrix[pos] = 0;
		if (mymatrix[pos] == 1)
			cct_showstr(posx * 2 + 2 * (l + 4), posy + h + 5, s0[op], color, COLOR_BLACK);
		else if (mymatrix[pos] == 0)
			cct_showch(posx * 2 + 2 * (l + 4), posy + h + 5, ' ', COLOR_HWHITE, COLOR_BLACK, 2);
	}
}

void erase_onesquare(int x, int y);

void draw_erase_square(int x, int y, int i, int j, int* mymatrix, int* _mymatrix, int color, int op) {
	int pos = i + j*5;
	if (op) {
		_mymatrix[pos] == 0 ? _mymatrix[pos] = 1 : _mymatrix[pos] = 0;
		mymatrix[pos] = 0;
		if (_mymatrix[pos] == 1)
			draw_one_square(x, y, color, "×");
		else if (_mymatrix[pos] == 0)
			erase_onesquare(x, y);
	}
	else {
		mymatrix[pos] == 0 ? mymatrix[pos] = 1 : mymatrix[pos] = 0;
		_mymatrix[pos] = 0;
		if (mymatrix[pos] == 1)
			draw_one_square(x, y, color, "〇");
		else if (mymatrix[pos] == 0)
			erase_onesquare(x, y);
	}
}

void draw_one_square(int x, int y, int color, const char str[3], int color2) {
	cct_showstr(x, y, "╔", color, color2); x += 2;
	cct_showstr(x, y, "═", color, color2); x += 2;
	cct_showstr(x, y, "╗", color, color2); x += 2;
	x -= 6, y += 1;
	cct_showstr(x, y, "║", color, color2); x += 2;
	cct_showstr(x, y, str, color, color2); x += 2;
	cct_showstr(x, y, "║", color, color2); x += 2;
	x -= 6, y += 1;
	cct_showstr(x, y, "╚", color, color2); x += 2;
	cct_showstr(x, y, "═", color, color2); x += 2;
	cct_showstr(x, y, "╝", color, color2); x += 2;
}

void erase_onesquare(int x, int y) {
	cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK, 6);
	y += 1;
	cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK, 6);
	y += 1;
	cct_showch(x, y, ' ', COLOR_HWHITE, COLOR_BLACK, 6);
	y += 1;
}

void adjust(int col, int l, int h, int* matrix, int* mymatrix, int* _mymatrix, int sidedif) {
	int color;
	int i, j;
	for (int pos = 0; pos < 225; ++pos) {
		i = pos / col, j = pos % col;
		if (matrix[pos] == 1) color = COLOR_HBLUE;
		else color = COLOR_RED;
		if (mymatrix[pos] == 1) {
			if (!sidedif)
				cct_showstr(j * 2 + 2 * (l + 4), i + h + 5, "〇", color, COLOR_BLACK);
			else
				draw_one_square((l + 4) * 2 + j * 8, (i + 1) * 4 + h + 1, color, "〇");
		}
		if (_mymatrix[pos] == 1) {
			if (!sidedif)
				cct_showstr(j * 2 + 2 * (l + 4), i + h + 5, "×", color, COLOR_BLACK);
			else
				draw_one_square((l + 4) * 2 + j * 8, (i + 1) * 4 + h + 1, color, "×");
		}
	}
}

void zmode(int col, int l, int h, int* matrix, bool isinputz, int sidedif) {
	int color1 = COLOR_HWHITE, color2 = COLOR_HWHITE;
	if (isinputz) color1 = COLOR_HBLACK, color2 = COLOR_BLACK;
	if (!sidedif) {
		int x = 2 * (l + 4), y = h + 5;
		for (int i = 0; i < col; ++i) {
			for (int j = 0; j < col / 5; ++j) {
				for (int jk = 0; jk < 5; ++jk) {
					if (matrix[(i)*col + j * 5 + jk] == 0) {
						cct_showch(x, y, ' ', COLOR_HWHITE, color2, 2); x += 2;
					}
					else if (matrix[(i)*col + j * 5 + jk] != 0) {
						cct_showstr(x, y, "〇", color1, color2);
						x += 2;
					}
				}
			}
			y++, x-=2*col;
		}
	}
	else {
		for (int i = 0; i < col; ++i) {
			for (int ik = 0; ik < col; ++ik) {
				if (matrix[i * col + ik] == 1) {
					if (!l)
						draw_one_square(4 + ik * 8, i * 4 + 3, color1,"〇",color2);
					else
						draw_one_square(2 * l + 8 + ik * 8, i * 4 + h + 5, color1, "〇",color2);
				}
			}
		}
	}
	
}

void game_mouse_keyboards_tool(int col, int l, int h, int* mymatrix, int* matrix, int sidedif, int hint[][8]) {
	int _mymatrix[225] = { 0 };
	char s1[] = { "ABCDEFGHIJKLMNO" };
	char s2[] = { "aabbccddeeffgghhiijjkkllmmnnoo" };
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int i, j;
	bool isinputz = false;

	cct_enable_mouse();

	/* 打印初始光标位置[0,0] */
	cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
	//		cout << "[当前鼠标位置] X:0  Y:0"; //打印初始鼠标位置

	while (loop) {
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT) {

			switch (maction) {
			case MOUSE_ONLY_MOVED:
				cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);
				judgeposition(X, Y, col, l, h, sidedif, i, j);
				break;
			case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
				cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);
				if (judgeposition(X, Y, col, l, h, sidedif,i,j)) {
					if (!sidedif)
						draw_single(X, Y, col, l, h, mymatrix, _mymatrix, 0, COLOR_HBLUE);
					else
						draw_erase_square((l + 4) * 2 + i * 8, (j + 1) * 4 + h + 1,i,j,mymatrix,_mymatrix ,COLOR_HBLUE,0);
					cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);
					cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
					cout << "读到左键        " << endl;
				}
				cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);
				judgeposition(X, Y, col, l, h,sidedif,i,j);
				if (isinputz) {
					zmode(col, l, h, matrix, isinputz, sidedif);
					adjust(col, l, h, matrix, mymatrix, _mymatrix, sidedif);
					cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
				}
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:			//按下右键
				cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);
				if (judgeposition(X, Y, col, l, h, sidedif, i, j)) {
					if (!sidedif)
						draw_single(X, Y, col, l, h, mymatrix, _mymatrix, 1, COLOR_HRED);
					else
						draw_erase_square((l + 4) * 2 + i * 8, (j + 1) * 4 + h + 1, i, j, mymatrix, _mymatrix, COLOR_HRED,1);
					cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);
					cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
					cout << "读到右键          " << endl;
				}
				cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);
				judgeposition(X, Y, col, l, h, sidedif, i, j);
				if (isinputz) {
					zmode(col, l, h, matrix, isinputz, sidedif);
					adjust(col, l, h, matrix, mymatrix, _mymatrix, sidedif);
					cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
				}
				break;
			} //end of switch(maction)
		} //end of if (CCT_MOUSE_EVENT)
		else if (ret == CCT_KEYBOARD_EVENT) {
			cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);

			switch (keycode1) {
			case 'Q':
				cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);
				loop = 0;
				cout << "[读到Q/q, 游戏结束]";
				break;
			case 'q':
				cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);
				loop = 0;
				cout << "[读到Q/q, 游戏结束]";
				break;
			case 'Y':
				cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);
				if (check(col, matrix, mymatrix, sidedif, hint))
					cout << "[提交成功]", loop = 0;
				else
					cout << ", 提交失败";
				break;
			case 'y':
				cct_gotoxy(12, col + h + 8 + sidedif * 5 * col / 2);
				if (check(col, matrix, mymatrix, sidedif, hint))
					cout << "[提交成功]", loop = 0;
				else
					cout << ", 提交失败";
				break;
			case 'Z':
				isinputz = !isinputz;
				zmode(col, l, h, matrix, isinputz, sidedif);
				adjust(col, l, h, matrix, mymatrix, _mymatrix, sidedif);
				cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
			case 'z':
				isinputz = !isinputz;
				zmode(col, l, h, matrix, isinputz, sidedif);
				adjust(col, l, h, matrix, mymatrix, _mymatrix, sidedif);
				cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
			case 224:
				switch (keycode2) {
				case KB_ARROW_UP:
					cout << "[读到上箭头]";
					break;
				case KB_ARROW_DOWN:
					cout << "[读到下箭头]";
					break;
				case KB_ARROW_LEFT:
					cout << "[读到左箭头]";
					break;
				case KB_ARROW_RIGHT:
					cout << "[读到右箭头]";
					break;
				}
				break;
			default:	//其他键直接打印ASCII值
				cout << "[读到键码] :" << keycode1 << '/' << keycode2 << endl;
				break;
			}//end of swicth(keycode1)
		}//end of else if(ret == CCT_KEYBOARD_EVENT）
	} //end of while(1)

	cct_disable_mouse();	//禁用鼠标
	cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标
}
