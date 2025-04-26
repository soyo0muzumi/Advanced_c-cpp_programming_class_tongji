#include <iostream>

using namespace std;

int main() {
	int lights[101];
	for (int i = 1; i <= 100; ++i) {
		int k = 1;
		while (i * k <= 100) {
			lights[i * k]++;
			k++;
		}
	}

	for (int i = 1; i <= 100; ++i) {
		if (lights[i] % 2 == 1) 
			cout << i << " ";
	}

	return 0;
}