#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int isrunyear(int y) {
	if (y % 4 == 0) {
		if (y % 100 == 0) {
			if (y % 400 == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 1;
		}
	}
	else {
		return 0;
	}
}

int isrightday(int m, int d, int feb) {
	if (d < 1)
		return 0;
	if (m == 1) {
		if (d > 31) 
			return 0;
	}
	if (m == 2) {
		if (d > feb)
			return 0;
	}
	if (m == 3) {
		if (d > 31)
			return 0;
	}
	if (m == 4) {
		if (d > 30)
			return 0;
	}
	if (m == 5) {
		if (d > 31)
			return 0;
	}
	if (m == 6) {
		if (d > 30)
			return 0;
	}
	if (m == 7) {
		if (d > 31)
			return 0;
	}
	if (m == 8) {
		if (d > 31)
			return 0;
	}
	if (m == 9) {
		if (d > 30)
			return 0;
	}
	if (m == 10) {
		if (d > 31)
			return 0;
	}
	if (m == 11) {
		if (d > 30)
			return 0;
	}
	if (m == 12) {
		if (d > 31)
			return 0;
	}
	return 1;
}

int zeller(int _y, int m, int d) {
	int c = _y / 100;
	int y = _y % 100;
	return y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
}

int main() {
	int y, m, d;
	while (1) {
		printf("请输入年[1900-2100]、月、日：\n");
		int ret = scanf("%d%d%d", &y, &m, &d);
		if (ret != 3) {
			printf("输入错误, 请重新输入\n");
		}
		if (ret == 0) {
			while (getchar() != '\n');
			continue;
		}

		if (y < 1900 || y > 2100) {
			printf("年份不正确，请重新输入\n");
			continue;
		}
		else if (m < 1 || m > 13) {
			printf("月份不正确，请重新输入\n");
			continue;
		}
		int feb = 28;
		if (isrunyear(y))
			feb = 29;
		if (!isrightday(m, d, feb)) {
			printf("日不正确，请重新输入\n");
			continue;
		}

		break;
	}
	int ret = zeller(y, m, d);

	while (ret < 0) {
		ret += 7;
	}

	ret %= 7;

	switch (ret)
	{
	case 0: 
		printf("星期日\n");
		break;
	case 1:
		printf("星期一\n");
		break;
	case 2:
		printf("星期二\n");
		break;
	case 3:
		printf("星期三\n");
		break;
	case 4:
		printf("星期四\n");
		break;
	case 5:
		printf("星期五\n");
		break;
	case 6:
		printf("星期六\n");
		break;
	default:
		break;
	}
}