#include <iostream>
using namespace std;

const char OTHER_CHARS[] = "!@#$%&*_=+.?";

int main() {
    char line[128];
    int len, u_min, l_min, d_min, o_min;
    int valid = 1; // 假设所有密码正确

    // 忽略第一行输入提示
    fgets(line, sizeof(line), stdin);

    // 读取5个参数
    if (!(cin >> len >> u_min >> l_min >> d_min >> o_min)) {
        valid = 0;
    }

    // 读取后续10行密码
    for (int i = 0; i < 10 && valid; i++) {
        char password[20]; // 足够容纳16字符+换行符+终止符
        getchar(); // 消耗上一行的换行符残留
        if (!fgets(password, sizeof(password), stdin)) {
            valid = 0;
            break;
        }

        // 去除换行符并检查长度
        size_t pw_len = strlen(password);
        if (pw_len > 0 && password[pw_len - 1] == '\n') {
            password[--pw_len] = '\0';
        }
        if (pw_len != len) {
            valid = 0;
            continue;
        }

        int u = 0, l = 0, d = 0, o = 0;
        for (int j = 0; j < pw_len; j++) {
            char c = password[j];
            if (isupper(c)) {
                u++;
            }
            else if (islower(c)) {
                l++;
            }
            else if (isdigit(c)) {
                d++;
            }
            else if (strchr(OTHER_CHARS, c) != NULL) {
                o++;
            }
            else { // 非法字符
                valid = 0;
                break;
            }
        }

        // 检查条件
        if (u < u_min || l < l_min || d < d_min || o < o_min) {
            valid = 0;
        }
        if (u + l + d + o != len) {
            valid = 0;
        }
    }

    if (valid)
        cout << "正确\n";
    else 
        cout << "错误\n";

    return 0;
}