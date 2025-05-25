/* 班级 3 学号 2452757 姓名 xqj */
#define _CRT_SECURE_NO_WARNINGS
#include "hanoi.h";
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
using namespace std;


int _count = 1;
int sleeptime = 0;
int A[11];
int B[11];
int C[11];
int a, b, c;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void clear() {
    a = 0;
    b = 0;
    c = 0;
    for (int i = 0; i <= 10; ++i) {
        A[i] = B[i] = C[i] = 0;
        _count = 1;
    }
}

void changearr(char src, char dst) {
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

void change(char src, char dst, int MenuItem) {
    // now arr is changed
    if (src == 'A') {
        if (dst == 'B') {
            if (MenuItem == 4)
                cct_gotoxy(Underpan_A_X_OFFSET-1, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - a - 2);
            else if (MenuItem == 8)
                cct_gotoxy(Underpan_A_X_OFFSET-1, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - a - 2);
            cout << "  ";
            if (MenuItem == 4)
                cct_gotoxy(Underpan_A_X_OFFSET-1 + 15, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - b-1);
            else if (MenuItem == 8)
                cct_gotoxy(Underpan_A_X_OFFSET-1 + 15, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - b-1);
            cout << setw(2) << B[b];
        }
        else if (dst == 'C') {
            if (MenuItem == 4)
                cct_gotoxy(Underpan_A_X_OFFSET-1, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - a - 2);
            else if (MenuItem == 8)
                cct_gotoxy(Underpan_A_X_OFFSET-1, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - a - 2);
            cout << "  ";
            if (MenuItem == 4)
                cct_gotoxy(Underpan_A_X_OFFSET-1 + 30, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - c - 1);
            else if (MenuItem == 8)
                cct_gotoxy(Underpan_A_X_OFFSET-1 + 30, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - c - 1);
            cout << setw(2) << C[c];
        }
    }
    else if (src == 'B') {
        if (dst == 'A') {
            if (MenuItem == 4)
                cct_gotoxy(Underpan_A_X_OFFSET-1 + 15, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - b - 2);
            else if (MenuItem == 8)
                cct_gotoxy(Underpan_A_X_OFFSET-1 + 15, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - b - 2);
            cout << "  ";
            if (MenuItem == 4)
                cct_gotoxy(Underpan_A_X_OFFSET-1, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - a - 1);
            else if (MenuItem == 8)
                cct_gotoxy(Underpan_A_X_OFFSET-1, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - a-1);
            cout << setw(2) << A[a];
        }
        else if (dst == 'C') {
            if (MenuItem == 4)
                cct_gotoxy(Underpan_A_X_OFFSET-1 + 15, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - b - 2);
            else if (MenuItem == 8)
                cct_gotoxy(Underpan_A_X_OFFSET-1 + 15, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - b - 2);
            cout << "  ";
            if (MenuItem == 4)
                cct_gotoxy(Underpan_A_X_OFFSET-1 + 30, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - c - 1);
            else if (MenuItem == 8)
                cct_gotoxy(Underpan_A_X_OFFSET-1 + 30, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - c - 1);
            cout << setw(2) << C[c];
        }
    }
    else if (src == 'C') {
        if (dst == 'A') {
            if (MenuItem == 4)
                cct_gotoxy(Underpan_A_X_OFFSET-1 + 30, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - c - 2);
            else if (MenuItem == 8)
                cct_gotoxy(Underpan_A_X_OFFSET-1 + 30, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - c - 2);
            cout << "  ";
            if (MenuItem == 4)
                cct_gotoxy(Underpan_A_X_OFFSET-1, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - a-1);
            else if (MenuItem == 8)
                cct_gotoxy(Underpan_A_X_OFFSET-1, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - a-1);
            cout << setw(2) << A[a];
        }
        else if (dst == 'B') {
            if (MenuItem == 4)
                cct_gotoxy(Underpan_A_X_OFFSET + 30, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - c - 2);
            else if (MenuItem == 8)
                cct_gotoxy(Underpan_A_X_OFFSET + 30, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - c - 2);
            cout << "  ";
            if (MenuItem == 4)
                cct_gotoxy(Underpan_A_X_OFFSET + 15, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - b-1);
            else if (MenuItem == 8)
                cct_gotoxy(Underpan_A_X_OFFSET + 15, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - b-1);
            cout << B[b];
        }
    }
}

void printarr() {
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

void init(char fmt[], int MenuItem) {
    if (MenuItem == 4)
        cct_cls();
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    printf(fmt);
    if (MenuItem == 4)
        cct_gotoxy(Underpan_A_X_OFFSET, MenuItem4_Start_Y + Underpan_A_Y_OFFSET);
    else if(MenuItem == 8)
        cct_gotoxy(Underpan_A_X_OFFSET, MenuItem8_Start_Y + Underpan_A_Y_OFFSET);
    cout << "A              B              C";
    if (MenuItem == 4)
        cct_gotoxy(Underpan_A_X_OFFSET - 2, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - 1);
    else if (MenuItem == 8)
        cct_gotoxy(Underpan_A_X_OFFSET - 2, MenuItem8_Start_Y + Underpan_A_Y_OFFSET - 1);
    cout << "===================================";
    for (int j = 1; j <= a; ++j) {
        if (MenuItem == 4)
            cct_gotoxy(Underpan_A_X_OFFSET - 1, MenuItem4_Start_Y + Underpan_A_Y_OFFSET * 2 + 1 - j);
        else if (MenuItem == 8)
            cct_gotoxy(Underpan_A_X_OFFSET - 1, MenuItem8_Start_Y + Underpan_A_Y_OFFSET * 2 + 1 - j);
        printf("%2d", A[j]);
    }
    for (int j = 1; j <= b; ++j) {
        if (MenuItem == 4)
            cct_gotoxy(Underpan_A_X_OFFSET + 14, MenuItem4_Start_Y + Underpan_A_Y_OFFSET * 2 + 1 - j);
        else if (MenuItem == 8)
            cct_gotoxy(Underpan_A_X_OFFSET + 14, MenuItem8_Start_Y + Underpan_A_Y_OFFSET * 2 + 1 - j);
        printf("%2d", B[j]);
    }
    for (int j = 1; j <= c; ++j) {
        if (MenuItem == 4)
            cct_gotoxy(Underpan_A_X_OFFSET + 29, MenuItem4_Start_Y + Underpan_A_Y_OFFSET * 2 + 1 - j);
        else if (MenuItem == 8)
            cct_gotoxy(Underpan_A_X_OFFSET + 29, MenuItem8_Start_Y + Underpan_A_Y_OFFSET * 2 + 1 - j);
        printf("%2d", C[j]);
    }

    if (MenuItem == 4)
        cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
    else if (MenuItem == 8)
        cct_gotoxy(MenuItem4_Start_X, MenuItem8_Start_Y);
    printf("初始:                ");
    printarr();

    if (MenuItem == 4) {
        if (sleeptime == 0) {
            char ch = _getch();
            while (ch != '\n' && ch != '\r');
        }
        else
            Sleep(sleeptime);
    }
}

void initarr(int n, int source) {
    // init
    if (source == 'A') {
        for (int i = n; i >= 1; --i) {
            A[n - i + 1] = i;
        }
        a = n;
    }
    else if (source == 'B') {
        for (int i = n; i >= 1; --i) {
            B[n - i + 1] = i;
        }
        b = n;
    }
    else if (source == 'C') {
        for (int i = n; i >= 1; --i) {
            C[n - i + 1] = i;
        }
        c = n;
    }
}

// 7 的子函数move
void move(char src, char dst) {
    static int __count = 1;
    int startX, endX;
    int startY, endY;
    int src_cur, dst_cur;
    if (src == 'A') startX = HDC_Start_X + (12 - A[a]) * HDC_Base_Width, startY = HDC_Start_Y - a * HDC_Base_High, src_cur = A[a];
    else if (src == 'B') startX = HDC_Start_X + (35 - B[b]) * HDC_Base_Width + HDC_Underpan_Distance, startY = HDC_Start_Y - b * HDC_Base_High, src_cur = B[b];
    else startX = HDC_Start_X + (58 - C[c]) * HDC_Base_Width + HDC_Underpan_Distance * 2, startY = HDC_Start_Y - c * HDC_Base_High, src_cur = C[c];

    changearr(src, dst);

    if (dst == 'A') endX = HDC_Start_X + (12 - A[a]) * HDC_Base_Width, endY = HDC_Start_Y - a * HDC_Base_High, dst_cur = A[a];
    else if (dst == 'B') endX = HDC_Start_X + (35 - B[b]) * HDC_Base_Width + HDC_Underpan_Distance, endY = HDC_Start_Y - b * HDC_Base_High, dst_cur = B[b];
    else endX = HDC_Start_X + (58 - C[c]) * HDC_Base_Width + HDC_Underpan_Distance * 2, endY = HDC_Start_Y - c * HDC_Base_High, dst_cur = C[c];

    // highest pos
    HDC_Top_Y;

    // move from src to highest pos
    for (int i = startY; i >= HDC_Top_Y; --i) {
        // clear pre line
        hdc_rectangle(startX, i + HDC_Base_High - 1, HDC_Base_Width * (src_cur * 2 + 1), HDC_Step_Y, HDC_COLOR[0]);
        // draw the cylinder
        if (i >= HDC_Start_Y - 13 * HDC_Base_High)
            hdc_rectangle(startX + HDC_Base_Width * (src_cur), i + HDC_Base_High, HDC_Base_Width, HDC_Step_Y, HDC_COLOR[11]);
        // draw new line ok
        hdc_rectangle(startX, i, HDC_Base_Width * (src_cur * 2 + 1), HDC_Step_Y, HDC_COLOR[src_cur]);

        if (sleeptime == 0 && __count <= 7) {
            char ch = _getch();
            while (ch != '\n' && ch != '\r');
        }
        else if (__count <= 7) {
            Sleep(sleeptime);
        }
    }

    // move x l->r
    if (startX < endX) {
        int i = startX;
        for (i = startX; i < endX; ++i) {
            // clear pre line
            hdc_rectangle(i, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[0]);

            // draw new line
            hdc_rectangle(i + HDC_Base_Width * (src_cur * 2 + 1), HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[src_cur]);

            if (sleeptime == 0 && __count <= 7) {
                char ch = _getch();
                while (ch != '\n' && ch != '\r');
            }
            else if (__count <= 7) {
                Sleep(sleeptime);
            }
        }
    }
    
    // move x r->l
    if (startX >= endX) {
        int i = startX;
        for (i = startX; i >= endX; --i) {
            // draw new line
            hdc_rectangle(i + HDC_Base_Width * (src_cur * 2 + 1), HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[0]);

            // clear pre line
            hdc_rectangle(i, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[src_cur]);

            if (sleeptime == 0 && __count <= 7) {
                char ch = _getch();
                while (ch != '\n' && ch != '\r');
            }
            else if (__count <= 7) {
                Sleep(sleeptime);
            }
        }
    }
    

    // move y from highest pos to endY
    for (int i = HDC_Top_Y; i < endY; ++i) {
        // clear pre line
        hdc_rectangle(endX, i, HDC_Base_Width * (src_cur * 2 + 1), HDC_Step_Y, HDC_COLOR[0]);
        // draw the cylinder
        if (i >= HDC_Start_Y - 12 * HDC_Base_High)
            hdc_rectangle(endX + HDC_Base_Width * (src_cur), i, HDC_Base_Width, HDC_Step_Y, HDC_COLOR[11]);
        // draw new line //cy
        hdc_rectangle(endX, i + HDC_Base_High , HDC_Base_Width * (src_cur * 2 + 1), HDC_Step_Y, HDC_COLOR[src_cur]);

        if (sleeptime == 0 && __count <= 7) {
            char ch = _getch();
            while (ch != '\n' && ch != '\r');
        }
        else if (__count <= 7) {
            Sleep(sleeptime);
        }
    }

    if (sleeptime != 0) __count++;
}

void print1(int n, char src, char dst, int MenuItem) {
    cout << " " << n << '#' << src << "-->" << dst << endl;
}

void print2(int n, char src, char dst, int MenuItem) {
    cout << setw(5) << _count++ << ":" << setw(3) << n << '#' << " " << src << "-->" << dst << endl;
}

void print3(int n, char src, char dst, int MenuItem) {
    printf("第%4d 步(%2d): %c-->%c ", _count++, n, src, dst);
    changearr(src, dst);
    printarr();
}

void print4(int n, char src, char dst, int MenuItem) {
    if (MenuItem == 4)
        cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
    if(MenuItem == 8) 
        cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y);
    printf("第%4d 步(%2d): %c-->%c ", _count++, n, src, dst);
    // mark // move first/change second
    if (MenuItem == 4)
        changearr(src, dst);
    printarr();
    change(src, dst, MenuItem);

    if (MenuItem == 4) {
        if (sleeptime == 0) {
            char ch = _getch();
            while (ch != '\n' && ch != '\r');
        }
        else {
            Sleep(sleeptime);
        }
    }
    
}

void print8(int n, char src, char dst, int MenuItem) {
    move(src, dst);
    print4(n, src, dst, MenuItem);
}

void printlist(int n, char src, char dst, int MenuItem) {
    switch (MenuItem) {
    case 1:
        print1(n, src, dst, MenuItem);
        break;
    case 2:
        print2(n, src, dst, MenuItem);
        break;
    case 3:
        print3(n, src, dst, MenuItem);
        break;
    case 4:
        print4(n, src, dst, MenuItem);
        break;
    case 8:
        print8(n, src, dst, MenuItem);
        break;
    }
}

/* hanoi */
void hanoi(int n, char src, char tmp, char dst, int MenuItem/*, void(*print)(int, char, char, int)*/)
{
    if (n == 1) {
        printlist(n, src, dst, MenuItem);
        return;
    }
    hanoi(n - 1, src, dst, tmp, MenuItem);
    printlist(n, src, dst, MenuItem);
    hanoi(n - 1, tmp, src, dst, MenuItem);
}




// the name of the 9 option
void basic_solution(int n, char src, char tmp, char dst) {
    hanoi(n, src, tmp, dst, 1);
    clear();
}

void basic_solution_saved(int n, char src, char tmp, char dst) {
    hanoi(n, src, tmp, dst, 2);
    clear();
}

void show_inside_arr_row(int n, char src, char tmp, char dst) {
    initarr(n, src);
    hanoi(n, src, tmp, dst, 3);
    clear();
}

void show_inside_arr_row_col(int n, char src, char tmp, char dst) {
    initarr(n, src);
    cout << "请输入移动速度(0-200：0-按回车单步演示 1-200:延时1-200ms) ";
    cin >> sleeptime;
    char fmt[100];
    sprintf(fmt, "从 %c 移动到 %c，共 %d 层，延时设置为 %dms", src, dst, n, sleeptime);
    init(fmt, 4);

    hanoi(n, src, tmp, dst, 4);
    clear();
}


void print_3_cylinder() {
    cct_cls();
    hdc_init();
    hdc_cls();

    hdc_rectangle(HDC_Start_X, HDC_Start_Y, HDC_Base_Width * 23, HDC_Base_High, HDC_COLOR[11]);
    Sleep(1000);
    hdc_rectangle(HDC_Start_X + HDC_Base_Width * 23 + HDC_Underpan_Distance, HDC_Start_Y, HDC_Base_Width * 23, HDC_Base_High, HDC_COLOR[11]);
    Sleep(1000);
    hdc_rectangle(HDC_Start_X + HDC_Base_Width * 23 * 2 + HDC_Underpan_Distance * 2, HDC_Start_Y, HDC_Base_Width * 23, HDC_Base_High, HDC_COLOR[11]);
    Sleep(1000);

    hdc_rectangle(HDC_Start_X + 12*HDC_Base_Width, HDC_Start_Y-12*HDC_Base_High, HDC_Base_Width, HDC_Base_High*12, HDC_COLOR[11]);
    Sleep(1000);
    hdc_rectangle(HDC_Start_X + HDC_Base_Width*35 + HDC_Underpan_Distance, HDC_Start_Y-12*HDC_Base_High, HDC_Base_Width, HDC_Base_High*12, HDC_COLOR[11]);
    Sleep(1000);
    hdc_rectangle(HDC_Start_X + HDC_Base_Width*58 + HDC_Underpan_Distance*2, HDC_Start_Y- HDC_Base_High*12, HDC_Base_Width, HDC_Base_High*12, HDC_COLOR[11]);
    Sleep(1000);

}


void print_3_cylinder_and_plates(int src, int n) {
    initarr(n, src);
    print_3_cylinder();
    for (int i = 1; i <= a; ++i) {
        hdc_rectangle(HDC_Start_X + (12-(a-i+1)) * HDC_Base_Width, HDC_Start_Y - i * HDC_Base_High, HDC_Base_Width*(23-2*(10-(a-i))), HDC_Base_High, HDC_COLOR[a-i+1]);
        Sleep(1000);
    }
    for (int i = 1; i <= b; ++i) {
        hdc_rectangle(HDC_Start_X + (35-(b-i+1)) * HDC_Base_Width + HDC_Underpan_Distance, HDC_Start_Y - i * HDC_Base_High, HDC_Base_Width*(23-2*(10-(b-i))), HDC_Base_High, HDC_COLOR[b-i+1]);
        Sleep(1000);
    }
    for (int i = 1; i <= c; ++i) {
        hdc_rectangle(HDC_Start_X + (58-(c-i+1)) * HDC_Base_Width + HDC_Underpan_Distance*2, HDC_Start_Y - i * HDC_Base_High, HDC_Base_Width*(23-2*(10-(c-i))), HDC_Base_High, HDC_COLOR[c-i+1]);
        Sleep(1000);
    }
    clear();
}

void print_3_cylinder_and_plates_and_move(int n, char src, char tmp, char dst) {
    cout << "请输入移动速度(0-1：0-按回车单步演示 1:延时1ms) ";
    cin >> sleeptime;
    char fmt[100];
    print_3_cylinder_and_plates(src, n);
    initarr(n, src);
    cct_gotoxy(Status_Line_X, Status_Line_Y);

    sprintf(fmt, "从 %c 移动到 %c，共 %d 层", src, dst, n);
    printf(fmt);
    if (n % 2) move(src, dst);
    else move(src, tmp);
    clear();
}

void print_3_cylinder_and_plates_and_automove(int n, char src, char tmp, char dst) {
    cout << "请输入移动速度(0-1：0-按回车单步演示 1:延时1ms) ";
    cin >> sleeptime;
    char fmt[100];
    print_3_cylinder_and_plates(src, n);
    initarr(n, src);
    sprintf(fmt, "从 %c 移动到 %c，共 %d 层", src, dst, n);
    init(fmt, 8);
    cct_gotoxy(Status_Line_X, Status_Line_Y);

    hanoi(n, src, tmp, dst, 8);
    clear();
}

int check(char src, char dst) {
    int src_cur = 0, dst_cur = 0;

    if (src == 'A') src_cur = A[a];
    else if (src == 'B') src_cur = B[b];
    else src_cur = C[c];

    if (dst == 'A') dst_cur = A[a];
    else if (dst == 'B') dst_cur = B[b];
    else dst_cur = C[c];

    if (dst_cur == 0) return 1;
    else if (src_cur == 0) return 2;
    else return !(src_cur > dst_cur);
}

void gamemove(int n, char src, char tmp, char dst) {
    char order[1000];
    while (1) {
        cct_gotoxy(Status_Line_X, Status_Line_Y - 1);
        cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";

        cin >> order;
        if (strlen(order) > 2) {
            cct_gotoxy(Status_Line_X, Status_Line_Y - 1);
            cout << "                                                                                                  ";
            continue;
        }
        while (getchar() != '\n' && getchar() != '\r');
        if (order[0] == 'a' || order[0] == 'b' || order[0] == 'c')
            order[0] = order[0] - 'a' + 'A';
        if (order[1] == 'a' || order[1] == 'b' || order[1] == 'c')
            order[1] = order[1] - 'a' + 'A';

        if (order[0] == 'A' || order[0] == 'B' || order[0] == 'C') {
            if (order[1] == 'A' || order[1] == 'B' || order[1] == 'C' && order[1] != order[0]) {
                if (check(order[0], order[1]) == 1)
                    break;
                else if (check(order[0], order[1]) == 2) {
                    cout << "\n源柱为空！";
                    Sleep(1000);
                    cct_gotoxy(Status_Line_X, Status_Line_Y);
                    cout << "        ";
                }
                else {
                    cout << "\n大盘压小盘，非法移动！";
                    Sleep(1000);
                    cct_gotoxy(Status_Line_X, Status_Line_Y);
                    cout << "                       ";
                }
            }
        }

    }
    move(order[0], order[1]);
    print4(n, order[0], order[1], 8);
    cct_gotoxy(Status_Line_X, Status_Line_Y - 1);
    cout << "                                                                                                  ";
}

void game(int n, char src, char tmp, char dst) {
    cout << "请输入移动速度(0-1：0-按回车单步演示 1:延时1ms) ";
    cin >> sleeptime;
    char fmt[100];
    print_3_cylinder_and_plates(src, n);
    initarr(n, src);
    sprintf(fmt, "从 %c 移动到 %c，共 %d 层", src, dst, n);
    init(fmt, 8);

    if (dst == 'A') {
        while (A[n] != 1) {
            gamemove(n, src, tmp, dst);
        }
    }
    else if (dst == 'B') {
        while (B[n] != 1) {
            gamemove(n, src, tmp, dst);
        }
    }
    else {
        while (C[n] != 1) {
            gamemove(n, src, tmp, dst);
        }
    }

    cct_gotoxy(Status_Line_X, Status_Line_Y);
    cout << "游戏结束!!!!!" << endl;
}