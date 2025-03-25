#include <iostream>
using namespace std;

int main() {
	cout << ("请输入找零值：") << endl;
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

	cout << "共" << count << "张找零，具体如下：" << endl;
	cout << "50元 : " << _50 << "张" << endl;
	cout << "20元 : " << _20 << "张" << endl;
	cout << "10元 : " << _10 << "张" << endl;
	cout << "5元  : " << _5 << "张" << endl;
	cout << "1元  : " << _1 << "张" << endl;
	cout << "5角  : " << _5jiao << "张" << endl;
	cout << "1角  : " << _1jiao << "张" << endl;
	cout << "5分  : " << _5fen << "张" << endl;
	cout << "1分  : " << _1fen << "张" << endl;
	
	return 0;
}