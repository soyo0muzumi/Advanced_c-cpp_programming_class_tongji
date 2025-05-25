/* 班级 3 学号 2452757 姓名 xqj */
#define _CRT_SECURE_NO_WARNINGS
#include "hanoi.h";
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

void input(int* n, char* source, char* tmp, char* target) {
	while (1) {
		printf("请输入汉诺塔的层数(1-10)\n");
		int ret = scanf("%d", n);
		while (getchar() != '\n');

		if (ret == 1 && (*n >= 1 && *n <= 10)) {
			break;
		}
	}

	while (1) {
		printf("请输入起始柱(A-C)\n");
		int ret = scanf("%c", source);
		while (getchar() != '\n');

		if (ret == 1 && ((*source >= 'A' && *source <= 'C') || (*source >= 'a' && *source <= 'c')))
			break;
	}

	while (1) {
		printf("请输入目标柱(A-C)\n");
		int ret = scanf("%c", target);
		if (ret == 1 && ((*target >= 'A' && *target <= 'C') || (*target >= 'a' && *target <= 'c')))
			break;
		while (getchar() != '\n');
	}

	if (*source == 'a' || *source == 'b' || *source == 'c') {
		*source = *source - 'a' + 'A';
		*target = *target - 'a' + 'A';
	}
	*tmp = ('A' - *source) + ('B' - *target) + 'C';
}

void to_be_continued(const int pos_x, const int pos_y)
{
	cct_gotoxy(pos_x, pos_y);

	//因为每次都从22行0列，如果本次打印内容比上次短，后面会有残留，因此先用100个空格填充掉（未做准确判断，简单假设打印内容不超过100）
	cout << setw(100) << ' ' << '\r'; //'\r'表示回到本行开头，不换行
	cout << "按回车键继续...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;

	return;
}


/***************************************************************************
  函数名称：main
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 将这段复制到main的最前面 */
	cout << "请确认当前cmd窗口的大小为40行*120列以上，字体为新宋体/16，按C继续，Q退出" << endl;
	while (1) {
		char ch = _getch();
		if (ch == 'C' || ch == 'c')
			break;
		if (ch == 'Q' || ch == 'q')
			return 0;
	}

	/* 从这里继续你的程序 */
	while (1) {
		cct_cls();
		menu();
		char option;
		while (1) {
			option = _getch();
			if (option >= '0' && option <= '9')
				break;
		}
		cout << option;
		cout << "\n\n";
		int n;
		char source, tmp, target;
		// init

		switch (option) {
		case '0':
			return 0;
		case '1':
			input(&n, &source, &tmp, &target);
			basic_solution(n, source, tmp, target);
			break;
		case '2':
			input(&n, &source, &tmp, &target);
			basic_solution_saved(n, source, tmp, target);
			break;
		case '3':
			input(&n, &source, &tmp, &target);
			show_inside_arr_row(n, source, tmp, target);
			break;
		case '4':
			input(&n, &source, &tmp, &target);
			show_inside_arr_row_col(n, source, tmp, target);
			break;
		case '5':
			print_3_cylinder();
			break;
		case '6':
			input(&n, &source, &tmp, &target);
			print_3_cylinder_and_plates(source, n);
			break;
		case '7':
			input(&n, &source, &tmp, &target);
			print_3_cylinder_and_plates_and_move(n, source, tmp, target);
			break;
		case '8':
			input(&n, &source, &tmp, &target);
			print_3_cylinder_and_plates_and_automove(n, source, tmp, target);
			break;
		case '9':
			input(&n, &source, &tmp, &target);
			game(n, source, tmp, target);
			break;
		}

		to_be_continued();
	}

	return 0;
}