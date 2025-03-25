#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
	cout << "请输入[0-100 亿)之间的数字:" << endl;
	double d;
	cin >> d;

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


	cout << "十亿位 ：" << shiyiwei << endl;
	cout << "亿位   ：" << yiwei << endl;
	cout << "千万位 ：" << qianwanwei << endl;
	cout << "百万位 ：" << baiwanwei << endl;
	cout << "十万位 ：" << shiwanwei << endl;
	cout << "万位   ：" << wanwei << endl;
	cout << "千位   ：" << qianwei << endl;
	cout << "十位   ：" << shiwei << endl;
	cout << "圆     ：" << shiyiwei << endl;
	cout << "角     ：" << jiao << endl;
	cout << "分     ：" << fen << endl;

	return 0;
}