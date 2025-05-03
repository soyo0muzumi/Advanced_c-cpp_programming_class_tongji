#include <iostream>
#include <iomanip>

using namespace std;

void islunlaryear(int y, int months[]) {
	if (y % 4 == 0) {
		months[2] = 29;
		if (y % 100 == 0) {
			months[2] = 28;
		}
		else if (y % 400 == 0) {
			months[2] = 29;
		}
	}
}

int zeller(int year, int month, int day) {
	// 处理1月和2月，视为上一年的13月和14月
	if (month < 3) {
		month += 12;
		year -= 1;
	}

	int q = day;
	int m = month;
	int K = year % 100;
	int J = year / 100;

	// 蔡勒公式计算
	int h = (q + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

	// 调整结果为0=星期日，1=星期一，...，6=星期六
	h = (h + 6) % 7;

	return h;
}

int main() {
	int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int curdays[13] = { 0,1,1,1,1,1,1,1,1,1,1,1,1 };
	char str1[] = "            ";
	char str2[] = "Sun Mon Tue Wed Thu Fri Sat";
	char str3[] = "     ";
	cout << "请输入年份[1900-2100]" << endl;
	int y, num;
	cin >> y;
	cout << "请输入每行打印的月份数[1/2/3/4/6/12]" << endl;
	cin >> num;
	cout << "2000年的日历: " << endl;
	islunlaryear(y, months);
	for (int i = 1; i <= 12/num; ++i) {
		for (int j = 1; j <= num; ++j) {
			cout << str1 << (i - 1) * num + j << "月" << str1 << str3;
		}
		cout << endl;
		for (int j = 1; j <= num; ++j) {
			cout << str2 << str3;
		}
		cout << endl;

		int col = 0;
		bool finish = false;
		while (!finish) {
			// 打印一行
			finish = true;
			for (int j = 1; j <= num; ++j) {
				int month = (i - 1) * num + j;
				if (curdays[month] == 1) {
					int ret = zeller(y, month, 1);
					while (ret < 0) {
						ret += 7;
					}

					ret %= 7;
					int count = ret;
					while (count--) {
						cout << "    ";
					}

					for (int k = 7 - ret; k > 0; --k) {
						cout << left << setw(4) << curdays[month]++;
					}
				}
				else {
					for (int i = 0; i < 7; ++i) {
						if (curdays[month] <= months[month]) {
							cout << left << setw(4) << curdays[month]++;
						}
						else {
							cout << "    ";
						}
					}
				}
				cout << "    ";

			}

			// check一下是不是打完了
			for (int j = 1; j <= num; ++j) {
				int month = (i - 1) * num + j;
				if (curdays[month] < months[month]) {
					finish = false;
					break;
				}
			}
			col++;
			cout << endl;
		}
		
		while (col < 6) {
			cout << endl;
			col++;
		}
		cout << endl;
	}
	

	return 0;
}