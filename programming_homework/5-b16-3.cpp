#include <iostream>
#include <string>
using namespace std;

void input(int grades[], string number[], string name[]) {
	for (int i = 1; i <= 10; ++i) {
		cout << ("请输入第") << i << "个人的学号、姓名、成绩\n";
		cin >> number[i];
		cin >> name[i];
		cin >> grades[i];
	}
}

void sort(string number[], int grades[], int order[]) {
	string mynumber[11];
	for (int i = 0; i <= 10; ++i) {
		mynumber[i] = number[i];
	}

	static int index = 1;
	while (index <= 10) {
		int maxi = 1;
		for (int i = 1; i <= 10; ++i) {
			if (mynumber[i] < mynumber[maxi])
				maxi = i;
		}
		order[index++] = maxi;
		mynumber[maxi][0] = 255;
	}
}

void output(int order[], int grades[], string number[], string name[]) {
	int i = 1;
	while (i <= 10) {
		cout << name[order[i]] << " ";
		cout << number[order[i]] << " ";
		cout << grades[order[i]] << endl;
		i++;
	}
}

int main() {
	int grades[11] = { 0 };
	string number[11];
	string name[11];
	int order[11];
	for (int i = 0; i <= 10; ++i) {
		order[i] = -1;
	}
	order[0] = 0;

	input(grades, number, name);
	sort(number, grades, order);

	printf("\n全部学生(学号升序):\n");
	output(order, grades, number, name);

	return 0;
}