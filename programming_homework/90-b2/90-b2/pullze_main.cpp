
#include <iostream>
#include "pullze.h"
#include <cstdio>
#include <conio.h>
#include <windows.h>

using namespace std;

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

/* 提示：空文件，仅为了提醒你不要忘记首行 && 不要把文件名弄错 */


int main() {
	bool isexit = false;
	while (!isexit) {
		cct_setfontsize("新宋体", 16);
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cct_setconsoleborder(120, 50);
		cct_cls();
		menu();
		char op;
		while (1) {
			op = _getch();
			if (toupper(op) >= 'A' && toupper(op) <= 'Q')
				break;
		}
		cout << op << endl;
		Sleep(500);
		option(toupper(op), isexit);
	}
	

	return 0;
}
