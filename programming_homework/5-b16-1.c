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

void sort(char number[][8], int grades[], int order[]) {
	char mynumber[11][8];
	for (int i = 0; i <= 10; ++i) {
		for (int j = 0; j < 8; ++j) {
			mynumber[i][j] = number[i][j];
		}
	}

	static int index = 1;
	int choose[11] = { 0 };
	int maxi = 1;
	while (maxi != 0) {
		maxi = 0;
		for (int i = 1; i <= 10; ++i) {
			if (strcmp(mynumber[i], mynumber[maxi]) > 0 && grades[i] >= 60)
				maxi = i;
		}
		if (grades[maxi] >= 60) {
			order[index++] = maxi;
			mynumber[maxi][0] = '\0';
			choose[maxi] = 1;
		}
		else
			order[index] = 0;
	}
}

void output(int order[], int grades[], char number[][8], char name[][9]) {
	int i = 1;
	while (order[i] != 0) {
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
	sort(number, grades, order);

	printf("\n及格名单(学号降序):\n");
	output(order, grades, number, name);

	return 0;
}