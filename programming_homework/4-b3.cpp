#include <iostream>
#include <iomanip>
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


int zeller(int _y, int m, int d) {
	int c = _y / 100;
	int y = _y % 100;
	return y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
}

void calendar(int y, int m)
{
	int ret = zeller(y, m, 1);
	while (ret < 0) {
		ret += 7;
	}

	/* 按需添加代码 */

	cout << y << "年" << m << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */

	int feb = 28;
	if (isrunyear(y))
		feb = 29;

	switch (m) {
	case 1: {
		m = 31;
		break;
	}
	case 2: {
		m = feb;
		break;
	}
	case 3: {
		m = 31;
		break;
	}
	case 4: {
		m = 30;
		break;
	}
	case 5: {
		m = 31;
		break;
	}
	case 6: {
		m = 30;
		break;
	}
	case 7: {
		m = 31;
		break;
	}
	case 8: {
		m = 31;
		break;
	}
	case 9: {
		m = 30;
		break;
	}
	case 10: {
		m = 31;
		break;
	}
	case 11: {
		m = 30;
		break;
	}
	case 12: {
		m = 31;
		break;
	}
	}

	ret %= 7;
	int count = ret;
	while (count--) {
		cout << "        ";
	}
	int i = 0;
	for (i = 1; i < 8 - ret; ++i) {
		cout << setw(4) << i << "    ";
	}
	cout << endl;
	i--;
	while (i <= m) {
		for (int j = 0; j < 7; ++j) {
			i++;
			cout << setw(4) << i << "    ";
			if (i == m) {
				break;
			}
		}
		cout << endl;
		if (i == m) {
			break;
		}
	}
	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}


int main() {
	int y, m;
	while (1) {
		cout << ("请输入年[1900-2100]、月") << endl;
		cin >> y >> m;
		if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12)
			break;

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
		

		break;
	}
	cout << endl;

	calendar(y, m);

	return 0;
}