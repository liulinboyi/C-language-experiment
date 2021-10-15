#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *transformerr(char *str);
// 函数写法错误
// 这里我们返回的是arr的地址，而arr是一个局部变量，当函数调用结束时，局部变量中数据可能已经不复存在了。
char *transformerr(char *str)
{
    int length = strlen(str);
    char *temp = str;
    char res[length];
    int i = 0;
    while (*temp)
    {
        res[i] = *temp;
        temp++;
        i++;
    }
    return res;
}

char *transform(char *str, char *arr);
// 函数写法错误
// 这里我们返回的是arr的地址，而arr是一个局部变量，当函数调用结束时，局部变量中数据可能已经不复存在了。
// https://www.awaimai.com/2819.html
char *transform(char *str, char *arr)
{
    char *temp = str;
    int i = 0;
    while (*temp)
    {
        arr[i] = *temp;
        temp++;
        i++;
    }
    return arr;
}

void foo(void);
void foo()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int *arr[] = {&a, &b, &c, &d};

    printf("%d\n", arr[0] - arr[1]);

    char *str = "1234456"; // 字面量赋值
    printf("%s\n", str);

    int length = strlen(str);
    char arrs[length];

    char *strarr = transform(str, arrs);
    // printf("%s\n", strarr[0]);
}

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    foo();
    system("pause");
    return 0;
}
