#include <iostream>

using namespace std;

int isrunyear(int y) {
	if (y % 4 == 0) {
		if (y % 100 == 0) {
			if (y % 400 == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 1;
		}
	}
	else {
		return 0;
	}
}

int isrightday(int m, int d, int feb) {
	if (d < 1)
		return 0;
	if (m == 1) {
		if (d > 31)
			return 0;
	}
	if (m == 2) {
		if (d > feb)
			return 0;
	}
	if (m == 3) {
		if (d > 31)
			return 0;
	}
	if (m == 4) {
		if (d > 30)
			return 0;
	}
	if (m == 5) {
		if (d > 31)
			return 0;
	}
	if (m == 6) {
		if (d > 30)
			return 0;
	}
	if (m == 7) {
		if (d > 31)
			return 0;
	}
	if (m == 8) {
		if (d > 31)
			return 0;
	}
	if (m == 9) {
		if (d > 30)
			return 0;
	}
	if (m == 10) {
		if (d > 31)
			return 0;
	}
	if (m == 11) {
		if (d > 30)
			return 0;
	}
	if (m == 12) {
		if (d > 31)
			return 0;
	}
	return 1;
}

int zeller(int _y, int m, int d) {
	int c = _y / 100;
	int y = _y % 100;
	return y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
}

int main() {
	int y, m, d;
	while (1) {
		cout << ("请输入年[1900-2100]、月、日：") << endl;
		cin >> y >> m >> d;

		if (cin.fail()) {
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		if (y < 1900 || y > 2100) {
			cout << ("年份不正确，请重新输入") << endl;
			continue;
		}
		else if (m < 1 || m > 13) {
			cout << ("月份不正确，请重新输入") << endl;
			continue;
		}
		int feb = 28;
		if (isrunyear(y))
			feb = 29;
		if (!isrightday(m, d, feb)) {
			cout << ("日不正确，请重新输入") << endl;
			continue;
		}

		break;
	}
	int ret = zeller(y, m, d);

	while (ret < 0) {
		ret += 7;
	}

	ret %= 7;

	switch (ret)
	{
	case 0:
		cout << ("星期日") << endl;
		break;
	case 1:
		cout << ("星期一") << endl;
		break;
	case 2:
		cout << ("星期二") << endl;
		break;
	case 3:
		cout << ("星期三") << endl;
		break;
	case 4:
		cout << ("星期四") << endl;
		break;
	case 5:
		cout << ("星期五") << endl;
		break;
	case 6:
		cout << ("星期六") << endl;
		break;
	default:
		break;
	}
}