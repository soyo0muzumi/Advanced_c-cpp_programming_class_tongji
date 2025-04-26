#include <iostream>

using namespace std;

int main() {
	int grades[101] = {0};
	int arr[1001] = {0};
	int count = 0;
	cout << ("请输入成绩（最多1000个），负数结束输入") << endl;

	while (count < 1000) {
		int num;
		cin >> num;
		if (num < 0)
			break;
		grades[num]++;
		arr[count++] = num;
	}

	cout << ("输入的数组为:") << endl;
	int j = 1;
	for (int i = 0; i < count; ++i) {
		cout << (arr[i]);
		j++;

		if (j == 11) {
			cout << ("\n");
			j = 1;
		}
	}
	cout << ("\n");

	cout << ("分数与名次的对应关系为:\n");
	int rank = 1;
	for (int i = 100; i >= 0; --i) {
		for (int j = 0; j < grades[i]; ++j) {
			cout << i << " " << rank << endl;
		}
		rank += grades[i];
	}

	return 0;
}