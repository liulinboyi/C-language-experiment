#include <stdio.h>
#include <stdlib.h>

// typedef char* va_list;
// https://blog.csdn.net/slvher/article/details/9881171
#define _ADDRESSOF(v) (&(v)) // 获取地址
// 返回参数n的size并保证4字节对齐（32-bits平台）
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v))
#define va_arg(ap, t) (*(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
#define va_end(ap) (ap = (va_list)0)

void foo(char *name, ... /*可变参数*/);

void foo(char *name, ... /*可变参数*/)
{
    // 按照约定，参数都在栈中，由于第一个参数是指针，所以要取得第一个参数的指针即内存地址，
    // 有了第一个参数的地址，参数是从右向左一依次入栈的
    // 所以取参数时，得到第一个参数的指针即内存地址，加上当前参数的大小就能得到下一个参数

    va_list args;
    va_start(args, name);         // 使args指向name
    char *arg1 = name;            // 第一个参数
    int arg2 = va_arg(args, int); // 第二个参数
    int arg3 = va_arg(args, int); // 第三个参数
    va_end(args);
    printf("the first arg %s,the second arg %d,the third arg %d\n", arg1, arg2, arg3);
}

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    char name[] = "xiaoming";
    int age = 20;
    int gender = 1;
    foo(name, age, gender);
    system("pause");
    return 0;
}
