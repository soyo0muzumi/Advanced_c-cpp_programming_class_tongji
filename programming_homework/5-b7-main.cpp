#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "5-b7.h"

using namespace std;

bool ifprint = 0;
int sleeptime = 0;
int _count = 1;
int A[11];
int B[11];
int C[11];
int a, b, c;

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

void init(char fmt[]) {
    cct_cls();
    cct_gotoxy(0, 0);
    printf(fmt);
    cct_gotoxy(12, 21);
    cout << "A         B         C";
    cct_gotoxy(10, 20);
    cout << "=========================";
    for (int j = 10; j > 0; --j) {
        cct_gotoxy(11, 20 - j);
        if (A[j] == 0)
            printf("  ");
        else
            printf("%2d", A[j]);
    }
    for (int j = 10; j > 0; --j) {
        cct_gotoxy(21, 20 - j);
        if (B[j] == 0)
            printf("  ");
        else
            printf("%2d", B[j]);
    }
    for (int j = 10; j > 0; --j) {
        cct_gotoxy(31, 20 - j);
        if (C[j] == 0)
            printf("  ");
        else
            printf("%2d", C[j]);
    }

    cct_gotoxy(31, 24);
    printf("初始:                ");
    if (ifprint) print();
}


void printxy(int n, char src, char tmp, char dst, char fmt[]) {
    cct_gotoxy(31, 24);
    printf("第%4d 步(%2d): %c-->%c ", _count++, n, src, dst);
    change(src, dst);
    if (ifprint) print();

    if (sleeptime == -1) {
        char ch = _getch();
        while (ch != '\n' && ch != '\r');
    }
    else {
        Sleep(sleeptime);
    }

    for (int j = 10; j > 0; --j) {
        cct_gotoxy(11, 20 - j);
        if (A[j] == 0)
            printf("  ");
        else
            printf("%2d", A[j]);
    }
    for (int j = 10; j > 0; --j) {
        cct_gotoxy(21, 20 - j);
        if (B[j] == 0)
            printf("  ");
        else
            printf("%2d", B[j]);
    }
    for (int j = 10; j > 0; --j) {
        cct_gotoxy(31, 20 - j);
        if (C[j] == 0)
            printf("  ");
        else
            printf("%2d", C[j]);
    }

    if (sleeptime == -1) {
        char ch = _getch();
        while (ch != '\n' && ch != '\r');
    }
    else {
        Sleep(sleeptime);
    }
}


void hanoi(int n, char src, char tmp, char dst, char fmt[])
{
    if (n == 1) {
        printxy(n, src, tmp, dst, fmt);
        return;
    }
    hanoi(n - 1, src, dst, tmp, fmt);
    printxy(n, src, tmp, dst, fmt);
    hanoi(n - 1, tmp, src, dst, fmt);
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
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

    int i; 
    int speed[6] = { -1,1000,500,200,50,0 };
    cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
    cin >> i;
    sleeptime = speed[i];

    cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
    cin >> ifprint;

    char fmt[100];
    if (ifprint)
        sprintf(fmt, "从 %c 移动到 %c，共 %d 层，延时设置为 %d，显示内部数组值", source, target, n, i);
    else
        sprintf(fmt, "从 %c 移动到 %c，共 %d 层，延时设置为 %d，不显示内部数组值", source, target, n, i);

    init(fmt);
    hanoi(n, source, tmp, target, fmt);

	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}