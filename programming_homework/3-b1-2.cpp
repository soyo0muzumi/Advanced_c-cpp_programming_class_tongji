#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const double Pi = 3.14159;
	cout << "请输入半径和高度" << endl;
	int r, h;
	cin >> r >> h;

	cout << "圆周长      ：" << fixed << setprecision(2) << Pi * 2 * r << endl;
	cout << "圆面积      ：" << fixed << setprecision(2) << Pi * r * r << endl;
	cout << "圆球表面积  ：" << fixed << setprecision(2) << Pi * 4 * r * r << endl;
	cout << "圆球体积    ：" << fixed << setprecision(2) << Pi * 4 * r * r * r / 3.0 << endl;
	cout << "圆柱体积    ：" << fixed << setprecision(2) << Pi * r * r * h << endl;

	return 0;
}