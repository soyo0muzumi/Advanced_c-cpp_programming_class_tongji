#include <iostream>

using namespace std;

void cal(char* bit, int len) {
	unsigned int ans = 0;
	unsigned int inv2[33];
	inv2[0] = 1;
	for (int i = 1; i <= 32; ++i) {
		inv2[i] = inv2[i - 1] * 2;
	}

	char* pstr = bit;
	unsigned int* parr = inv2 + len - 1;
	while (*pstr != '\0') {
		ans += *parr * (*pstr - '0');
		pstr++;
		parr--;
	}

	cout << ans << endl;
}

int main() {
	cout << "请输入一个0/1组成的字符串，长度不超过32\n";
	char bit[32];
	cin >> bit;
	cal(bit, strlen(bit));

	return 0;
}