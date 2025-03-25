#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
	printf("请输入三角形的两边及其夹角\n");
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	double d = sin(c * 3.14159 / 180);
	printf("三角形的面积是：%.3f", 0.5 * a * b * d);

	return 0;
}