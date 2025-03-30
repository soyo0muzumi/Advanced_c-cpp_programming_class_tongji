/* 班级 学号 2452757 姓名 */
#include <iostream>
#include <iomanip>

using namespace std;

// 123456789
//int main() {
//	int no = 0;
//	
	// 和为1953
	// 拆成 1800 + 140 + 13
	// 这样18 + 14 + 13 = 45// 刚好是和//其他情况不行
	// 问题转化为求3个数，和为18，14，13

	//int i1, i2, i3, i4, i5, i6, i7, i8, i9;
	//// i1 + i2 + i3 = 18

	//for (i1 = 9; i1 > 0; --i1) {
	//	for (i2 = i1 - 1; i2 > 0; --i2) {
	//		if (18 - i1 - i2 > 0)
	//			i3 = 18 - i1 - i2;
	//		else 
	//			continue;
	//		for (i4 = 9; i4 > 0; --i4) {
	//			if (i4 == i1 || i4 == i2 || i4 == i3) 
	//				continue;
	//			for (i5 = i4 - 1; i5 > 0; --i5) {
	//				if (i5 == i1 || i5 == i2 || i5 == i3)
	//					continue;
	//				if (14 - i4 - i5 > 0)
	//					i6 = 14 - i5 - i4;
	//				else
	//					continue;
	//				for (i7 = 9; i7 > 0; --i7) {
	//					if (i7 == i1 || i7 == i2 || i7 == i3 || i7 == i4 || i7 == i5 || i7 == i6)
	//						continue;
	//					for (i8 = i7 - 1; i8 > 0; --i8) {
	//						if (i8 == i1 || i8 == i2 || i8 == i3 || i8 == i4 || i8 == i5 || i8 == i6)
	//							continue;
	//						if (13 - i7 - i8 > 0) {
	//							i9 = 13 - i7 - i8;

	//							// i1 ~ i9 全部知道
	//							cout << "No." << setw(3) << ++no << i3 * 100 + i6 * 10 + i9  << "+" << i2 * 100 + i5 * 10 + i8 << "+"<< i1 * 100 + i4 * 10 + i7 << "=1953" << endl;
	//							cout << "No." << setw(3) << ++no << i3 * 100 + i6 * 10 + i9 << "+" << i2 * 100 + i5 * 10 + i7 << "+" << i1 * 100 + i4 * 10 + i8 << "=1953" << endl;
	//							cout << "No." << setw(3) << ++no << i3 * 100 + i6 * 10 + i9 << "+" << i2 * 100 + i5 * 10 + i7 << "+" << i1 * 100 + i4 * 10 + i8 << "=1953" << endl;


	//						}

	//						else
	//							continue;
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	/*return 0;
}*/
// 不用数组太麻烦了
// 直接暴力求解


#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

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
			cout << "No." << setw(3) << ++count << ":" << a << "+" << b << "+" << c << "=1953" << endl;
		}
	}

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}