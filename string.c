#include <stdio.h>
#include <stdlib.h>

/* 将字符串src_拼接到dst_后,将回拼接的串地址 */
char *strcat(char *dst_, const char *src_)
{
    char *str = dst_;
    while (*str++);
    --str; // 别看错了，--str是独立的一句，并不是while的循环体

    while (*src_)
    {
        // 内联汇编和下面C语言代码等价
        asm volatile("movl %0,%%ebx;/* 将src_的内存地址传送到基址寄存器ebx */ \
                      movb (%%ebx),%%al;/* 从基址寄存器ebx为基址寻址，得到src_内存地址处的值，传送到8位通用寄存器al */ \
                      movl %1,%%ebx;/* 将str的内存地址传送到基址寄存器ebx */ \
                      movb %%al,(%%ebx); /* 将8位通用寄存器al存储的值，传送到以基址寄存器ebx为基址寻址，得到str的内存地址处 */"
                     :
                     : "m"(src_), "m"(str)
                     : "memory", "al", "ebx");

        // 与下面代码等价

        // char temp= *src_;
        // *str = temp; // 汇编寻址(*str)传送
        str++;
        src_++;
    }
    return dst_;
}

int main(int argc, char const *argv[])
{
    /* code */
    // 正确用法
    char a[] = "123";
    char b[] = "456";
    char *c[] = {b}; // 指针数组
    printf("c:%s\n", *c);
    // 错误用法
    // char *a = "123";
    // char *b = "456";
    printf("a:%p\n", a); // 字符串与数组本身就是指针(头指针)
    printf("b:%p\n", b);
    strcat(a, b);
    printf("%s\n", a);

    system("pause");
    return 0;
}
