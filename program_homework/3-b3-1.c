#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	printf("请输入[0-100 亿)之间的数字:\n");
	double d;
	scanf("%lf", &d);

	int _d = d / 10;
	double __d = d / 10 - _d;

	int shiwei = _d % 10;
	_d /= 10;
	int baiwei = _d % 10;
	_d /= 10;
	int qianwei = _d % 10; 
	_d /= 10;
	int wanwei = _d % 10; 
	_d /= 10;
	int shiwanwei = _d % 10; 
	_d /= 10;
	int baiwanwei = _d % 10; 
	_d /= 10;
	int qianwanwei = _d % 10; 
	_d /= 10;
	int yiwei = _d % 10; 
	_d /= 10;
	int shiyiwei = _d % 10;

	__d *= 1000;
	int ___d = __d;
	if ((__d - ___d) * 10 > 5) ___d++;

	int fen = ___d % 10;
	___d /= 10;
	int jiao = ___d % 10;
	___d /= 10;
	int yuan = ___d % 10;


	printf("十亿位 ：%d\n", shiyiwei);
	printf("亿位   ：%d\n", yiwei);
	printf("千万位 ：%d\n", qianwanwei);
	printf("百万位 ：%d\n", baiwanwei);
	printf("十万位 ：%d\n", shiwanwei);
	printf("万位   ：%d\n", wanwei);
	printf("千位   ：%d\n", qianwei);
	printf("百位   ：%d\n", baiwei);
	printf("十位   ：%d\n", shiwei);
	printf("圆     ：%d\n", yuan);
	printf("角     ：%d\n", jiao);
	printf("分     ：%d\n", fen);

	return 0;
}