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

void sort(int grades[], int order[]) {
	int mygrades[11];
	for (int i = 0; i <= 10; ++i) {
		mygrades[i] = grades[i];
	}

	mygrades[0] = 101;
	static int index = 1;
	int mini = 1;
	while (order[index] == -1) {
		mini = 0;
		for (int i = 1; i <= 10; ++i) {
			if (mygrades[i] < mygrades[mini])
				mini = i;
		}
		if (mygrades[mini] < 60) {
			order[index++] = mini;
			mygrades[mini] = 101;
		}
		else
			order[index] = 0;
	}
}

void output(int order[], int grades[], string number[], string name[]) {
	int i = 1;
	while (order[i] != 0) {
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
	sort(grades, order);

	printf("\n不及格名单(成绩升序):\n");
	output(order, grades, number, name);

	return 0;
}