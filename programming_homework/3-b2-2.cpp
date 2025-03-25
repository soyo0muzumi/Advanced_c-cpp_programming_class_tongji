#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main() {
	cout << "请输入一个[1..30000]之间的整数:" << endl;
	int num;
	cin >> num;
	int gewei = num % 10;
	num /= 10;
	int shiwei = num % 10;
	num /= 10;
	int baiwei = num % 10;
	num /= 10;
	int qianwei = num % 10;
	num /= 10;
	int wanwei = num % 10;

	cout << "万位: " << wanwei << endl;
	cout << "千位: " << qianwei << endl;
	cout << "百位: " << baiwei << endl;
	cout << "十位: " << shiwei << endl;
	cout << "个位: " << gewei << endl;

	return 0;
}