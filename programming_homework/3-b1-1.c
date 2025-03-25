#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	const double Pi = 3.14159;

	printf("请输入半径和高度\n");
	int r, h;
	scanf("%d%d", &r, &h);
	printf("圆周长      ：%.2f\n", Pi * 2 * r);
	printf("圆面积      ：%.2f\n", Pi * r * r);
	printf("圆球表面积  ：%.2f\n", Pi * 4 * r * r);
	printf("圆球体积    ：%.2f\n", Pi * 4 * r * r * r / 3.0);
	printf("圆柱体积    ：%.2f\n", Pi * r * r * h);
	
	return 0;
}