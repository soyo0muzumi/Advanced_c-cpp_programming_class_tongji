#include <iostream>

using namespace std;

bool is_reverse_str(char* str, int len) {
	char* begin = str, *end = str + len - 1;
	while (begin < end) {
		if (*begin != *end)
			return false;
		begin++;
		end--;
	}
	return true;
}

int main() {
	cout << "请输入一个长度小于80的字符串（回文串）\n";
	char str[82];
	fgets(str, 80, stdin);
	str[strlen(str) - 1] = '\0';
	if (is_reverse_str(str, strlen(str)))
		cout << "yes";
	else
		cout << "no";

	return 0;
}