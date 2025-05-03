#include <iostream>

using namespace std;

int main() {
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	int matrix[9][9] = { 0 };
	int judgemat[27][9] = { 0 };

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int x;
			while (1) {
				cin >> x;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				}
				else if (x < 1 || x > 9) {
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				}
				else {
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
			}
			matrix[i][j] = x;
			judgemat[i][x-1]++;
			judgemat[j + 9][x-1]++;

			if (i < 3) {
				if (j < 3) judgemat[18][x - 1]++;
				else if (j < 6) judgemat[19][x - 1]++;
				else judgemat[20][x - 1]++;
			}
			else if (i < 6) {
				if (j < 3) judgemat[21][x - 1]++;
				else if (j < 6) judgemat[22][x - 1]++;
				else judgemat[23][x - 1]++;
			}
			else {
				if (j < 3) judgemat[24][x - 1]++;
				else if (j < 6) judgemat[25][x - 1]++;
				else judgemat[26][x - 1]++;
			}
		}
	}

	for (int i = 0; i < 27; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (judgemat[i][j] != 1) {
				cout << "不是数独的解" << endl;
				return 0;
			}
		}
	}

	cout << "是数独的解" << endl;

	return 0;
}