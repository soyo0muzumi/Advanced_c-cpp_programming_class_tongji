/* 学号 姓名 班级 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (!str)
        return 0;
    const char* p = str;
    int ret = 0;
    while (*p != '\0') {
        ret++;
        p++;
    }
    return ret;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s2 == NULL)
        return s1;
    if (s1 == NULL)
        return s1;
    int n1 = tj_strlen(s1);
    char* ps1 = s1 + n1;
    const char* ps2 = s2;

    while(*ps2 != '\0') {
        *ps1 = *ps2;
        ps1++, ps2++;
    }
    *ps1 = '\0';

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s2 == NULL)
        return s1;
    if (s1 == NULL)
        return s1;
    int n1 = tj_strlen(s1);
    char* ps1 = s1 + n1;
    const char* ps2 = s2;
    while (ps2 != s2 + len) {
        *ps1 = *ps2;
        ps1++, ps2++;
    }
    *ps1 = '\0';

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL)
        return s1;
    if (s2 == NULL) {
        *s1 = '\0';
        return s1;
    }
    
    char* ps1 = s1;
    const char* ps2 = s2;
    while (*ps2 != '\0') {
        *ps1 = *ps2;
        ps1++, ps2++;
    }
    *ps1 = '\0';

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    if (s1 == NULL)
        return s1;
    if (s2 == NULL) {
        return s1;
    }
    
    char* ps1 = s1;
    const char* ps2 = s2;
    int _len = len;
    if (len > tj_strlen(s2))
        _len = tj_strlen(s2);
    while (ps2 != s2 + _len) {
        *ps1 = *ps2;
        ps1++, ps2++;
    }

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    const char* ps1 = s1, *ps2 = s2;
    while (*ps1 != '\0' || *ps2 != '\0') {
        if (*ps1 == *ps2) {
            ps1++, ps2++;
            continue;
        }
        else
            return *ps1 - *ps2;
    }

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char toupper(char ch) {
    if ('a' <= ch && ch <= 'z')
        ch = ch - 'a' + 'A';
    return ch;
}
char tolower(char ch) {
    if ('A' <= ch && ch <= 'Z')
        ch = ch + 'a' - 'A';
    return ch;
}

int tj_strcasecmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    const char* ps1 = s1;
    const char* ps2 = s2;

    while (*ps1 != '\0' || *ps2 != '\0') {
        if (*ps1 == *ps2) {
            ps1++, ps2++;
            continue;
        }
        else if ((('a' <= *ps1 && *ps1 <= 'z') || ('A' <= *ps1 && *ps1 <= 'Z')) &&
            (('a' <= *ps2 && *ps2 <= 'z') || ('A' <= *ps2 && *ps2 <= 'Z'))) {
            if (toupper(*ps1) == toupper(*ps2)) {
                ps1++, ps2++;
                continue;
            }
            else
                return toupper(*ps1) - toupper(*ps2);
        }
        else
            return *ps1 - *ps2;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    const char* ps1 = s1, * ps2 = s2;
    int count = 0;
    while ((*ps1 != '\0' || *ps2 != '\0') && count < len) {
        count++;
        if (*ps1 == *ps2) {
            ps1++, ps2++;
            continue;
        }
        else
            return *ps1 - *ps2;
    }

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    const char* ps1 = s1;
    const char* ps2 = s2;
    int count = 0;

    while ((*ps1 != '\0' || *ps2 != '\0') && count < len) {
        count++;
        if (*ps1 == *ps2) {
            ps1++, ps2++;
            continue;
        }
        else if ((('a' <= *ps1 && *ps1 <= 'z') || ('A' <= *ps1 && *ps1 <= 'Z')) &&
            (('a' <= *ps2 && *ps2 <= 'z') || ('A' <= *ps2 && *ps2 <= 'Z'))) {
            if (toupper(*ps1) == toupper(*ps2)) {
                ++ps1, ++ps2;
                continue;
            }
            else
                return toupper(*ps1) - toupper(*ps2);
        }
        else
            return *ps1 - *ps2;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (!str)
        return NULL;
    char* p = str;
    while (*p) {
        *p = toupper(*p);
        ++p;
    }

    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (!str)
        return NULL;
    char* p = str;
    while (*p) {
        *p = tolower(*p);
        ++p;
    }

    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (!str)
        return 0;
    const char* p = str;
    while (*p) {
        if (*p == ch)
            break;
        p++;
    }
    if (*p == '\0')
        return 0;
    else
        return p - str + 1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL)
        return 0;
    const char* p1 = str;
    const char* psubstr = substr;
    while (*p1 != '\0') {
        const char* cur = p1;
        const char* p2 = psubstr;
        while (*cur == *p2) {
            cur++, p2++;
        }
        if (*p2 == '\0')
            return p1 - str + 1;

        p1++;
    }

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (!str)
        return 0;
    const char* p = str + tj_strlen(str) - 1;
    while (p != str) {
        if (*p == ch)
            break;
        p--;
    }
    if (p == str)
        return 0;
    else
        return p - str + 1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL)
        return 0;
    const char* p1 = str + tj_strlen(str) - 1;
    const char* psubstr = substr + tj_strlen(substr) - 1;
    while (p1 != str) {
        const char* cur = p1;
        const char* p2 = psubstr;
        while (*cur == *p2) {
            cur--, p2--;
            if (p2 == substr && *cur == *p2)
                return p1 - str + 2 - tj_strlen(substr);
        }
        p1--;
    }

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (!str)
        return 0;
    char* left = str;
    char* right = str + tj_strlen(str) - 1;
    while (left < right) {
        char tmp = *left;
        *left = *right;
        *right = tmp;

        left++, right--;
    }

    return str;
}