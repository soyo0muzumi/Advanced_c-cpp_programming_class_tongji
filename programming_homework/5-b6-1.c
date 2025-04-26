#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count = 1;
int A[11];
int B[11];
int C[11];
int a, b, c;

void print() {
    int numofspace = 21;
    int printed10 = 0;
    printf("A: ");
    for (int i = 1; i <= a; ++i) {
        printf("%d ", A[i]);
        if (A[i] == 10) printed10 = 1;
    }
    for (int i = 0; i < numofspace - 2 * a - printed10; ++i) {
        printf(" ");
    }

    printed10 = 0;
    printf("B: ");
    for (int i = 1; i <= b; ++i) {
        printf("%d ", B[i]);
        if (A[i] == 10) printed10 = 1;
    }
    for (int i = 0; i < numofspace - 2 * b - printed10; ++i) {
        printf(" ");
    }

    printed10 = 0;
    printf("C: ");
    for (int i = 1; i <= c; ++i) {
        printf("%d ", C[i]);
        if (A[i] == 10) printed10 = 1;
    }
    for (int i = 0; i < numofspace - 2 * c - printed10; ++i) {
        printf(" ");
    }

    printf("\n");
}

void change(char src, char dst) {
    if (src == 'A') {
        if (dst == 'B') {
            B[++b] = A[a];
            A[a] = 0;
            a--;
        }
        else if (dst == 'C') {
            C[++c] = A[a];
            A[a] = 0;
            a--;
        }
    }
    else if (src == 'B') {
        if (dst == 'A') {
            A[++a] = B[b];
            B[b] = 0;
            b--;
        }
        else if (dst == 'C') {
            C[++c] = B[b];
            B[b] = 0;
            b--;
        }
    }
    else if (src == 'C') {
        if (dst == 'A') {
            A[++a] = C[c];
            C[c] = 0;
            c--;
        }
        else if (dst == 'B') {
            B[++b] = C[c];
            C[c] = 0;
            c--;
        }
    }
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
        printf("第%4d 步(%2d): %c-->%c ", count++, n, src, dst);
        change(src, dst);
        print();
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    printf("第%4d 步(%2d): %c-->%c ", count++, n, src, dst);
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
        printf("请输入汉诺塔的层数(1-10)\n");
        int ret = scanf("%d", &n);
        while (getchar() != '\n');

        if (ret == 1 && (n >= 1 && n <= 10)) {
            break;
        }
    }

    char source, target;
    while (1) {
        printf("请输入起始柱(A-C)\n");
        int ret = scanf("%c", &source);
        while (getchar() != '\n');

        if (ret == 1 && ((source >= 'A' && source <= 'C') || (source >= 'a' && source <= 'c')))
            break;
    }

    while (1) {
        printf("请输入目标柱(A-C)\n");
        int ret = scanf("%c", &target);
        if (ret == 1 && ((target >= 'A' && target <= 'C') || (target >= 'a' && target <= 'c')))
            break;
        while (getchar() != '\n');
    }

    char tmp;
    if (source == 'a' || source == 'b' || source == 'c') {
        source = source - 'a' + 'A';
        target = target - 'a' + 'A';
    }
    tmp = ('A' - source) + ('B' - target) + 'C';
    printf("移动步骤为:\n");
    // init
    if (source == 'A') {
        for (int i = 0; i <= n; ++i) {
            A[i] = i;
        }
        a = n;
    }
    else if (source == 'B') {
        for (int i = 0; i <= n; ++i) {
            B[i] = i;
        }
        b = n;
    }
    else if (source == 'C') {
        for (int i = 0; i <= n; ++i) {
            C[i] = i;
        }
        c = n;
    }
    printf("初始:                ");
    print();

    hanoi(n, source, tmp, target);

    return 0;
}