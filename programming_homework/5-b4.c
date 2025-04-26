#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int grades[101] = {0};
	int arr[1001] = {0};
	int count = 0;
	printf("请输入成绩（最多1000个），负数结束输入\n");

	while (count < 1000) {
		int num;
		int ret = scanf("%d", &num);
		if (num < 0)
			break;
		if (ret == 1) {
			grades[num]++;
			arr[count++] = num;
		}
	}

	printf("输入的数组为:\n");
	int j = 1;
	for (int i = 0; i < count; ++i) {
		printf("%d ", arr[i]);
		j++;

		if (j == 11) {
			printf("\n");
			j = 1;
		}
	}
	printf("\n");

	printf("分数与人数的对应关系为:\n");
	// int rank = 1;
	/*for (int i = 99; i >= 0; --i) {
		for (int j = 0; j < grades[i]; ++j) {
			printf("%d %d\n", i, rank);
		}
		rank += grades[i];
	}*/

	for (int i = 99; i >= 0; --i) {
		if (grades[i] != 0) {
			printf("%d %d\n", i, grades[i]);
		}
	}

	return 0;
}