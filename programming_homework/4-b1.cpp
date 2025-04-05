/* 学号 2452757 姓名 xqj 班级 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}

/***************************************************************************
  函数名称：
  功    能：打印位
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void printwei(int wei, bool print) {
	if (print) {
		if (wei == 5) {
			cout << "亿";
		}
		else if (wei == 4) {
			cout << "万";
		}
		else if (wei == 3) {
			cout << "千";
		}
		else if (wei == 2) {
			cout << "百";
		}
		else if (wei == 1) {
			cout << "拾";
		}
		else {
			cout << "元";
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：打印每个千位
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

void geteverythousandupwrite(int td, int wei) {
	bool flag_of_zero = false;
	if (wei != 5)
		flag_of_zero = true;

	daxie(td / 1000, flag_of_zero);
	printwei(3, td / 1000);

	if (!(td / 1000) && !((td / 100) % 10))
		flag_of_zero = false;

	daxie((td / 100) % 10, flag_of_zero);
	printwei(2, (td / 100) % 10);

	if (!((td / 100) % 10) && !((td / 10) % 10))
		flag_of_zero = false;

	daxie((td / 10) % 10, flag_of_zero);
	printwei(1, (td / 10) % 10);

	if (!((td / 100) % 10) && !((td / 10) % 10) && !(td % 10))
		flag_of_zero = false;

	daxie(td % 10, flag_of_zero);

	printwei(wei, 1);
}

/* 可根据需要自定义其它函数(也可以不定义) */


int main() {
	cout << "请输入[0-100 亿)之间的数字:" << endl;

	double price;
	cin >> price;
	int integerPart = (price / 10);
	int _d = integerPart;
	double __d = price / 10 - _d;
	__d *= 1000;
	int ___d = __d;
	if ((__d - ___d) * 10 > 5) ___d++;
	int decimalPart = ___d % 100;
	int gewei = ___d / 100;

	// 处理整数部分 注意没有个位
	int billionSection = integerPart / 10000000;
	int millionSection = (integerPart / 1000) % 10000;
	int thousandSection = integerPart % 1000;
	thousandSection = thousandSection * 10 + gewei;

	geteverythousandupwrite(billionSection, 5);
	geteverythousandupwrite(millionSection, 4);
	geteverythousandupwrite(thousandSection, 0);


	// 处理小数部分

	if (decimalPart / 10 != 0) {
		daxie(decimalPart / 10, 1);
		cout << "角";
	}
	if (decimalPart % 10 != 0) {
		daxie(decimalPart / 10 == 0, 1);
		cout << "分";
	}
	else if (decimalPart / 10 != 0) {
		cout << "整";
	}
	else {
		cout << "整";
	}

}