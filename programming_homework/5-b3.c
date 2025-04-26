#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void islunlaryear(int y, int months[]) {
	if (y % 4 == 0) {
		months[2] = 29;
		if (y % 100 == 0) {
			months[2] = 28;
		}
		else if (y % 400 == 0) {
			months[2] = 29;
		}
	}
}

void pre(int y, int presum[], int months[]) {
	islunlaryear(y, months);

	for (int i = 1; i <= 12; ++i) {
		presum[i] = presum[i - 1] + months[i];
	}
}

int cal(int months[], int m, int d, int presum[]) {
	if (months[m] < d || d < 1)
		printf("输入错误-日与月的关系非法\n");
	else {
		return presum[m - 1] + d;
	}

	return 0;
}

int main() {
	int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int presum[13] = { 0 };
	int y, m, d;
	printf("请输入年，月，日\n");
	int _d = 0;
	scanf("%d%d%d", &y, &m, &d);
	if (m < 1 || m > 12) {
		printf("输入错误-月份不正确\n");
		return 0;
	}

	pre(y, presum, months);
	_d = cal(months, m, d, presum);

	if (_d != 0) {
		printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, _d);
	}

	return 0;
}