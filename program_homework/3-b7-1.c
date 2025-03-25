#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	printf("请输入找零值：\n");
	float change;
	scanf("%f", &change);

	int integerPart = change;
	float _f = change - integerPart;
	_f *= 100;
	int __f = _f;
	if ((__f - _f) * 10 > 5) 
		__f++;
	int decimalPart = __f;

	int _50 = 0;
	int _20 = 0;
	int _10 = 0;
	int _5 = 0;
	int _1 = 0;
	int _5jiao = 0;
	int _1jiao = 0;
	int _5fen = 0;
	int _1fen = 0;

	int count = 0;
	// 整数
	if (integerPart >= 50) {
		count++;
		_50++;
		integerPart -= 50;
	}
	if (integerPart >= 20) {
		count++;
		_20++;
		integerPart -= 20;
	}
	if (integerPart >= 20) {
		count++;
		_20++;
		integerPart -= 20;
	}
	if (integerPart >= 10) {
		count++;
		_10++;
		integerPart -= 10;
	}
	if (integerPart >= 5) {
		count++;
		_5++;
		integerPart -= 5;
	}
	if (integerPart > 0) {
		count += integerPart;
		_1 = integerPart;
	}
	// 小数
	if (decimalPart >= 50) {
		count++;
		_5jiao++;
		decimalPart -= 50;
	}
	if (decimalPart >= 10) {
		count++;
		_1jiao++;
		decimalPart -= 10;
	}
	if (decimalPart >= 10) {
		count++;
		_1jiao++;
		decimalPart -= 10;
	}
	if (decimalPart >= 10) {
		count++;
		_1jiao++;
		decimalPart -= 10;
	}
	if (decimalPart >= 10) {
		count++;
		_1jiao++;
		decimalPart -= 10;
	}
	if (decimalPart >= 5) {
		count++;
		_5fen++;
		decimalPart -= 5;
	}
	if (decimalPart > 0) {
		count += decimalPart;
		_1fen = decimalPart;
	}

	printf("共%d张找零，具体如下：\n", count);
	printf("50元 : %d张\n", _50);
	printf("20元 : %d张\n", _20);
	printf("10元 : %d张\n", _10);
	printf("5元  : %d张\n", _5);
	printf("1元  : %d张\n", _1);
	printf("5角  : %d张\n", _5jiao);
	printf("1角  : %d张\n", _1jiao);
	printf("5分  : %d张\n", _5fen);
	printf("1分  : %d张\n", _1fen);

	return 0;
}