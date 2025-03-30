#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

// ¥Ú”°99≥À∑®±Ì
int main() {
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%dx%d=%-3d ", i, j, j*i);
		}
		printf("\n");
	}

	return 0;
}