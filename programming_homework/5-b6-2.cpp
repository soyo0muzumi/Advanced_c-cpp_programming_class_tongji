#include <iostream>
#include <iomanip>

using namespace std;

int _count = 1;
int ABC[3][11];
int abc[3];

void print() {
    char _ABC[3] = { 'A', 'B', 'C' };
    int numofspace = 21;
    
    for (int j = 0; j < 3; ++j) {
        int printed10 = 0;
        cout << _ABC[j] << ": ";
        for (int i = 1; i <= abc[j]; ++i) {
            cout << ABC[j][i] << " ";
            if (ABC[j][i] == 10) printed10 = 1;
        }
        for (int i = 0; i < numofspace - 2 * abc[j] - printed10; ++i) {
            cout << (" ");
        }
    }

    printf("\n");
}

void change(char src, char dst) {
    ABC[dst - 'A'][abc[dst - 'A'] + 1] = ABC[src - 'A'][abc[src - 'A']];
    ABC[src - 'A'][abc[src - 'A']] = 0;
    abc[dst - 'A']++, abc[src - 'A']--;
}

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
        cout << "第" << setw(4) << _count++ << "步" << " (" << setw(2) << n << ")" << ": " << src << "-->" << dst << " ";
        change(src, dst);
        print();
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    cout << "第" << setw(4) << _count++ << "步" << " (" << setw(2) << n << ")" << ": " << src << "-->" << dst << " ";
    change(src, dst);
    print();
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
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;   //读入x的方式必须是 cin>>int型变量，不允许其他方式

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (n >= 1 && n <= 10)
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

    // init
    for (int i = 0; i <= n; ++i) {
        ABC[source - 'A'][i] = i;
    }
    abc[source - 'A'] = n;

    cout << ("初始:                ");
    print();

    hanoi(n, source, tmp, target);

    return 0;
}