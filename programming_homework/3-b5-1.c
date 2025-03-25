#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	printf("请输入年，月，日\n");
	int y, m, d;
	int _d = 0;
	scanf("%d%d%d", &y, &m, &d);
	int Jan = 31, Feb = 28, Mar = 31, Apr = 30, May = 31, Jun = 30, Jul = 31, Aug = 31, Sep = 30, Oct = 31, Nov = 30, Dec = 31;
	if (y % 4 == 0) {
		Feb = 29;
		if (y % 100 == 0) {
			Feb = 28;
		}
		else if (y % 400 == 0) {
			Feb = 29;
		}
	}
	if (m < 1 || m > 12)
		printf("输入错误-月份不正确\n");
	else {
		if (m == 1) {
			if (d <= 0 || d > Jan)
				printf("输入错误-日与月的关系非法\n");
			else {
				_d = d;
			}
		}
		else if (m == 2) {
			if (d <= 0 || d > Feb)
				printf("输入错误-日与月的关系非法\n");
			else {
				_d = Jan + d;
			}
		}
		else if (m == 3) {
			if (d <= 0 || d > Mar)
				printf("输入错误-日与月的关系非法\n");
			else {
				_d = Jan + Feb + d;
			}
		}
		else if (m == 4) {
			if (d <= 0 || d > Apr)
				printf("输入错误-日与月的关系非法\n");
			else {
				_d = Jan + Feb + Mar + d;
			}
		}
		else if (m == 5) {
			if (d <= 0 || d > May)
				printf("输入错误-日与月的关系非法\n");
			else {
				_d = Jan + Feb + Mar + Apr + d;
			}
		}
		else if (m == 6) {
			if (d <= 0 || d > Jun)
				printf("输入错误-日与月的关系非法\n");
			else {
				_d = Jan + Feb + Mar + Apr + May + d;
			}
		}
		else if (m == 7) {
			if (d <= 0 || d > Jul)
				printf("输入错误-日与月的关系非法\n");
			else {
				_d = Jan + Feb + Mar + Apr + May + Jun + d;
			}
		}
		else if (m == 8) {
			if (d <= 0 || d > Aug)
				printf("输入错误-日与月的关系非法\n");
			else {
				_d = Jan + Feb + Mar + Apr + May + Jun + Jul + d;
			}
		}
		else if (m == 9) {
			if (d <= 0 || d > Sep)
				printf("输入错误-日与月的关系非法\n");
			else {
				_d = Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + d;
			}
		}
		else if (m == 10) {
			if (d <= 0 || d > Oct)
				printf("输入错误-日与月的关系非法\n");
			else {
				_d = Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + Sep + d;
			}
		}
		else if (m == 11) {
			if (d <= 0 || d > Nov)
				printf("输入错误-日与月的关系非法\n");
			else {
				_d = Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + Sep + Oct + d;
			}
		}
		else if (m == 12) {
			if (d <= 0 || d > Dec)
				printf("输入错误-日与月的关系非法\n");
			else {
				_d = Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + Sep + Oct + Dec + d;
			}
		}
	}

	if (_d != 0) {
		printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, _d);
	}

	return 0;
}