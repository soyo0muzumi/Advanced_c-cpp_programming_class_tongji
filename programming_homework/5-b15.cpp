#include <iostream>

using namespace std;

int main() {
	char str[3][128];
    int upper = 0, lower = 0, digit = 0, space = 0, other = 0;

    for (int i = 0; i < 3; i++) {
        cout << "请输入第" << i + 1 << "行\n";
        fgets(str[i], 128, stdin);
        int len = strlen(str[i]);
        if (len > 0 && str[i][len - 1] == '\n') {
            str[i][len - 1] = '\0';
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; str[i][j] != '\0'; j++) {
            char c = str[i][j];
            if (c >= 'A' && c <= 'Z') {
                upper++;
            }
            else if (c >= 'a' && c <= 'z') {
                lower++;
            }
            else if (c >= '0' && c <= '9') {
                digit++;
            }
            else if (c == ' ') {
                space++;
            }
            else {
                other++;
            }
        }
    }

    cout << "大写：" << upper << endl;
    cout << "小写：" << lower << endl;
    cout << "数字：" << digit << endl;
    cout << "空格：" << space << endl;
    cout << "其它：" << other << endl;

    return 0;
}