#include <iostream>
using namespace std;

int main() {
	cout << "请输入年，月，日" << endl;
	int y, m, d;
	int _d = 0;
	cin >> y >> m >> d;
	int Jan = 31, Feb = 28, Mar = 31, Apr = 30, May = 31, Jun = 30, Jul = 31, Aug = 31, Sep = 30, Oct = 31, Nov = 30, Dec = 31;
	if (y % 4 == 0) {
		Feb = 29;
		if (y % 100 == 0) {
			Feb = 28;
		}
		else if (y % 400 == 0) {
			Feb = 29;
		}
	}
	if (m < 1 || m > 12)
		cout << "输入错误-月份不正确" << endl;
	else {
		if (m == 1) {
			if (d <= 0 || d > Jan)
				cout << "输入错误-日与月的关系非法" << endl;
			else {
				_d = d;
			}
		}
		else if (m == 2) {
			if (d <= 0 || d > Feb)
				cout << "输入错误-日与月的关系非法" << endl;
			else {
				_d = Jan + d;
			}
		}
		else if (m == 3) {
			if (d <= 0 || d > Mar)
				cout << "输入错误-日与月的关系非法" << endl;
			else {
				_d = Jan + Feb + d;
			}
		}
		else if (m == 4) {
			if (d <= 0 || d > Apr)
				cout << "输入错误-日与月的关系非法" << endl;
			else {
				_d = Jan + Feb + Mar + d;
			}
		}
		else if (m == 5) {
			if (d <= 0 || d > May)
				cout << "输入错误-日与月的关系非法" << endl;
			else {
				_d = Jan + Feb + Mar + Apr + d;
			}
		}
		else if (m == 6) {
			if (d <= 0 || d > Jun)
				cout << "输入错误-日与月的关系非法" << endl;
			else {
				_d = Jan + Feb + Mar + Apr + May + d;
			}
		}
		else if (m == 7) {
			if (d <= 0 || d > Jul)
				cout << "输入错误-日与月的关系非法" << endl;
			else {
				_d = Jan + Feb + Mar + Apr + May + Jun + d;
			}
		}
		else if (m == 8) {
			if (d <= 0 || d > Aug)
				cout << "输入错误-日与月的关系非法" << endl;
			else {
				_d = Jan + Feb + Mar + Apr + May + Jun + Jul + d;
			}
		}
		else if (m == 9) {
			if (d <= 0 || d > Sep)
				cout << "输入错误-日与月的关系非法" << endl;
			else {
				_d = Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + d;
			}
		}
		else if (m == 10) {
			if (d <= 0 || d > Oct)
				cout << "输入错误-日与月的关系非法" << endl;
			else {
				_d = Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + Sep + d;
			}
		}
		else if (m == 11) {
			if (d <= 0 || d > Nov)
				cout << "输入错误-日与月的关系非法" << endl;
			else {
				_d = Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + Sep + Oct + d;
			}
		}
		else if (m == 12) {
			if (d <= 0 || d > Dec)
				cout << "输入错误-日与月的关系非法" << endl;
			else {
				_d = Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + Sep + Oct + Dec + d;
			}
		}
	}
	if (_d != 0) {
		cout << y << "-" << m << "-" << d << "是" << y << "年的第" << _d << "天" << endl;
	}

	return 0;
}