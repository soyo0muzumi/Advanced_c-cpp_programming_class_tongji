/* 学号 2452757 姓名 xqj 班级 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        cout << " " << n << '#' << src << "-->" << dst << endl;
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    cout << " " << n << '#' << src << "-->" << dst << endl;
    hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n;
    while (1) {
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> n;   //读入x的方式必须是 cin>>int型变量，不允许其他方式

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (n >= 1 && n <= 16)
            break;
    }

    char source, target;
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> source;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if ((source >= 'A' && source <= 'C') || (source >= 'a' && source <= 'c'))
            break;
    }

    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> target;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if ((target >= 'A' && target <= 'C') || (target >= 'a' && target <= 'c'))
            break;
    }
    char tmp;
    if (source == 'a' || source == 'b' || source == 'c') {
        source = source - 'a' + 'A';
        target = target - 'a' + 'A';
    }
    tmp = ('A' - source) + ('B' - target) + 'C';
    cout << "移动步骤为:\n";
    hanoi(n, source, tmp, target);

    return 0;
}