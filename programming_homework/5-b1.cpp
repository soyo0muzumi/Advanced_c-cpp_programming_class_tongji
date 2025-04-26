#include <iostream>

using namespace std;


int main() {
	int arr[21];
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	int count = 0;
	int num;
	while (count < 20) {
		cin >> num;
		if (num <= 0) break;

		arr[count++] = num;
	}

	if (count == 0) {
		cout << "无有效输入" << endl;
		return 0;
	}

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "原数组为：" << endl;
	for (int i = 0; i < count; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "请输入要插入的正整数" << endl;
	int newnum;
	cin >> newnum;

	int pos = 0;
	while (arr[pos] < newnum) pos++;

	for (int i = count; i >= pos; --i) {
		arr[i + 1] = arr[i];
	}

	arr[pos] = newnum;

	cout << "插入后的数组为：" << endl;
	count++;
	for (int i = 0; i < count; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}