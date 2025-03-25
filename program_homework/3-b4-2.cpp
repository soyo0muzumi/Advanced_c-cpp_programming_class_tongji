#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << "请输入三角形的两边及其夹角" << endl;
	int a, b, c;
	cin >> a >> b >> c;
	double d = sin(c * 3.14159 / 180);
	cout << "三角形的面积是："<< fixed << setprecision(3) << 0.5 * a * b * d << endl;

	return 0;
}