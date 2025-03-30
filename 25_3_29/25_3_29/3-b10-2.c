/* 班级 学号 2452757 姓名 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int count = 0;

	// 遍历所有可能的三位数a
	for (int a = 123; a <= 987; ++a) {
		int a1 = a / 100;
		int a2 = (a / 10) % 10;
		int a3 = a % 10;

		// 检查a的各位是否有效
		if (a1 == 0 || a2 == 0 || a3 == 0)
			continue;
		if (a1 == a2 || a1 == a3 || a2 == a3)
			continue;

		// 遍历所有可能的三位数b
		for (int b = a; b <= 987; ++b) {
			int b1 = b / 100;
			int b2 = (b / 10) % 10;
			int b3 = b % 10;

			// 检查b的各位是否有效且不与a重复
			if (b1 == 0 || b2 == 0 || b3 == 0)
				continue;
			if (b1 == b2 || b1 == b3 || b2 == b3)
				continue;
			if (b1 == a1 || b1 == a2 || b1 == a3)
				continue;
			if (b2 == a1 || b2 == a2 || b2 == a3)
				continue;
			if (b3 == a1 || b3 == a2 || b3 == a3)
				continue;

			// 计算c并检查范围
			int c = 1953 - a - b;
			if (c < 100 || c > 999 || c < a || c < b) continue;

			int c1 = c / 100;
			int c2 = (c / 10) % 10;
			int c3 = c % 10;

			// 检查c的各位是否有效且不与a、b重复
			if (c1 == 0 || c2 == 0 || c3 == 0)
				continue;
			if (c1 == c2 || c1 == c3 || c2 == c3)
				continue;
			if (c1 == a1 || c1 == a2 || c1 == a3 || c1 == b1 || c1 == b2 || c1 == b3)
				continue;
			if (c2 == a1 || c2 == a2 || c2 == a3 || c2 == b1 || c2 == b2 || c2 == b3)
				continue;
			if (c3 == a1 || c3 == a2 || c3 == a3 || c3 == b1 || c3 == b2 || c3 == b3)
				continue;

			// 输出有效组合并计数
			printf("No.%-3d:%d+%d+%d=1953\n", ++count, a, b, c);
		}
	}

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}