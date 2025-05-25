#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void input(int grades[], char number[][8], char name[][9]) {
	for (int i = 1; i <= 10; ++i) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i);
		scanf("%s", number[i]);
		scanf("%s", name[i]);
		scanf("%d", &grades[i]);
	}
}

void sort(int grades[], int order[]) {
	char mygrades[11];
	for (int i = 0; i <= 10; ++i) {
		mygrades[i] = grades[i];
	}

	static int index = 1;
	while (index <= 10) {
		int maxi = 1;
		for (int i = 1; i <= 10; ++i) {
			if (mygrades[i] > mygrades[maxi])
				maxi = i;
		}
		order[index++] = maxi;
		mygrades[maxi] = -1;
	}
}

void output(int order[], int grades[], char number[][8], char name[][9]) {
	int i = 1;
	while (i <= 10) {
		printf("%s ", name[order[i]]);
		printf("%s ", number[order[i]]);
		printf("%d\n", grades[order[i]]);
		i++;
	}
}

int main() {
	int grades[11] = { 0 };
	char number[11][8] = { 0 };
	char name[11][9] = { 0 };
	int order[11];
	for (int i = 0; i <= 10; ++i) {
		order[i] = -1;
	}
	order[0] = 0;

	input(grades, number, name);
	sort(grades, order);

	printf("\n全部学生(成绩降序):\n");
	output(order, grades, number, name);

	return 0;
}