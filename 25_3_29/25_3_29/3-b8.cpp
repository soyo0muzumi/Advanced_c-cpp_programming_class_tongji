#include <iostream>
#include <iomanip>

using namespace std;
int main() {
	cout << "请输入x的值[-10 ~ +65]" << endl;
	bool did = false;
	while (!did) {
		int x;
		cin >> x;
		if (x < -10 || x > 65) {
			cout << "输入非法，请重新输入" << endl;
		}
		else {
			did = true;
			double sub = 1;
			double ret = 0;
			int i = 1;
			while (fabs(sub) > 1e-6) {
				sub = 1;
				for (int j = 1; j < i; ++j) {
					sub = sub * x / j;
				}
				ret += sub;
				++i;
			}
			cout << setiosflags(ios::fixed) << setprecision(10) << ret << endl;
		}
	}

	return 0;
}