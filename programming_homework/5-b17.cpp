#include <iostream>
#include <time.h>

using namespace std;

const char OTHER_CHARS[] = "!@#$%&*_=+.?"; // 其他符号数组

// 输入验证函数
int false_input(int len, int upper, int lower, int digit, int other) {
    if (len < 12 || len > 16) {
        cout << "密码长度[" <<len << "]不正确\n";
        return 0;
    }
    if (upper < 2 || lower < 2 || digit < 2 || other < 2) {
        if (upper < 2) 
            cout << "大写字母个数[" << upper << "]不正确\n";
        if (lower < 2) 
            cout << "小写字母个数[" << lower << "]不正确\n";
        if (digit < 2) 
            cout << "数字个数[" << digit << "]不正确\n";
        if (other < 2) 
            cout << "其它符号个数[" << other << "]不正确\n";
        return 0;
    }
    if (upper + lower + digit + other > len) {
        printf("所有字符类型之和[%d+%d+%d+%d]大于总密码长度[%d]\n", upper, lower, digit, other, len);
        return 0;
    }
    return 1;
}

void shuffle(char* array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// 密码生成函数
void generate_passwords(int len, int u_min, int l_min, int d_min, int o_min) {
    srand((unsigned int)time(NULL));
    printf("%d %d %d %d %d\n", len, u_min, l_min, d_min, o_min);

    for (int p = 0; p < 10; p++) {
        char password[17] = { 0 }; // 最大16+1
        int index = 0;

        // 填充必须的字符
        for (int i = 0; i < u_min; i++) password[index++] = 'A' + rand() % 26;
        for (int i = 0; i < l_min; i++) password[index++] = 'a' + rand() % 26;
        for (int i = 0; i < d_min; i++) password[index++] = '0' + rand() % 10;
        for (int i = 0; i < o_min; i++) password[index++] = OTHER_CHARS[rand() % (strlen(OTHER_CHARS))];

        // 填充剩余字符
        int remaining = len - (u_min + l_min + d_min + o_min);
        while (remaining-- > 0) {
            switch (rand() % 4) {
            case 0: password[index++] = 'A' + rand() % 26; break;
            case 1: password[index++] = 'a' + rand() % 26; break;
            case 2: password[index++] = '0' + rand() % 10; break;
            case 3: password[index++] = OTHER_CHARS[rand() % (strlen(OTHER_CHARS))]; break;
            }
        }

        // 打乱顺序并输出
        shuffle(password, len);
        cout << password << endl;
    }
}

void printError(const char message[]) {
    cout << message << endl;
}

int main() {
    int len, upper, lower, digit, other;
    cout << ("请输入密码长度 (12-16)，大写字母个数(>=2)，小写字母个数(>=2)，数字个数(>=2)，其它符号个数(>=2)\n");

    // 读取输入并验证
    if (!(cin >> len >> upper >> lower >> digit >> other)) {
        printError("输入非法");
        return 1;
    }

    if (!false_input(len, upper, lower, digit, other)) {
        return 0;
    }

    generate_passwords(len, upper, lower, digit, other);
    return 0;
}