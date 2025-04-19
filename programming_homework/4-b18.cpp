#include <iostream>
using namespace std;

int max(int a, int b, int c) {
	int ret = a;
	if (ret < b) ret = b;
	if (ret < c) ret = c;

	return ret;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int max(int a, int b, int c, int d) {
	int ret = a;
	if (ret < b) ret = b;
	if (ret < c) ret = c;
	if (ret < d) ret = d;

	return ret;
}

int main() {
	int num;
	int a, b, c, d;
	int num;
	int a = 1, b = 1, c = 1, d = 1;
	while (1) {
		std::cout << "请输入个数num及num个正整数：" << std::endl;
		std::cin >> num;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (num > 4 || num < 2) {
			std::cout << "个数输入错误" << std::endl;
			return 0;
		}
		int i = 1;
		if (i <= num) {
			std::cin >> a;
			i++;
		}
		if (i <= num) {
			std::cin >> b;
			i++;
		}
		if (i <= num) {
			std::cin >> c;
			i++;
		}
		if (i <= num) {
			std::cin >> d;
			i++;
		}

		if (a > 0 && b > 0 && c > 0 && d > 0)
			break;

	int ret = 0;
	if (num == 2) ret = max(a, b);
	else if (num == 3) ret = max(a, b, c);
	else if (num == 4) ret = max(a, b, c, d);

	cout << "max=" << ret << endl;
}