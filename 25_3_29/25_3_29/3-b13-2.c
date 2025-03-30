#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int y, m;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		int ret = scanf("%d%d", &y, &m);
		if (ret == 2 && y >= 2000 && y <= 2030 && m >= 1 && m <= 12)
			break;
		printf("输入非法, 请重新输入\n");
		if (ret == 0) {
			while (getchar() != '\n');
		}
		
	}

	int d;
	while (1) {
		printf("请输入%d年%d月1日的星期(0 - 6表示星期日 - 星期六) : ", y, m);
		int ret = scanf("%d", &d);
		if (ret == 1 && d >= 0 && d <= 6)
			break;
		printf("输入非法, 请重新输入\n");
		if (ret == 0) {
			while (getchar() != '\n');
		}

	}
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
	printf( "%d年%d月的月历为:\n", y, m);
	printf( "星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	switch (m) {
	case 1: {
		m = Jan;
		break;
	}
	case 2: {
		m = Feb;
		break;
	}
	case 3: {
		m = Mar;
		break;
	}
	case 4: {
		m = Apr;
		break;
	}
	case 5: {
		m = May;
		break;
	}
	case 6: {
		m = Jun;
		break;
	}
	case 7: {
		m = Jul;
		break;
	}
	case 8: {
		m = Aug;
		break;
	}
	case 9: {
		m = Sep;
		break;
	}
	case 10: {
		m = Oct;
		break;
	}
	case 11: {
		m = Nov;
		break;
	}
	case 12: {
		m = Dec;
		break;
	}
	}
	int count = d;
	while (count--) {
		printf("        ");
	}
	int i = 0;
	for (i = 1; i < 8 - d; ++i) {
		printf("%4d    " ,i);
	}
	printf("\n");

	while (i <= m) {
		for (int j = 0; j < 7; ++j) {
			i++;
			printf("%4d    ", i);
			if (i == m) {
				break;
			}
		}
		printf("\n");
		if (i == m) {
			break;
		}
	}

	return 0;
}