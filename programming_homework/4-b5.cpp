/* 学号 2452757 班级 姓名 xqj */
#include <iostream>

using namespace std;

int peaches(int days) {
	if (days == 1) {
		return 1;
	}

	return 2 * (peaches(days - 1) + 1);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int days;

	cout << "请输入第几天的桃子数为1" << endl;
	cin >> days;		//输入[1-30]间的正整数即可，不考虑输入错误

	cout << "第1天买的桃子数量=" << peaches(days) << endl;

	return 0;
}