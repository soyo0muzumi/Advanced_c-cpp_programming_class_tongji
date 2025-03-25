#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	printf("请输入一个[1..30000]之间的整数:\n");
	int num = 0;
	scanf("%d", &num);
	int gewei = num % 10;
	num /= 10;
	int shiwei = num % 10;
	num /= 10;
	int baiwei = num % 10;
	num /= 10;
	int qianwei = num % 10;
	num /= 10;
	int wanwei = num % 10;

	printf("万位：%d\n", wanwei);
	printf("千位：%d\n", qianwei);
	printf("百位：%d\n", baiwei);
	printf("十位：%d\n", shiwei);
	printf("个位：%d\n", gewei);

	return 0;
}