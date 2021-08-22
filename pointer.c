#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    // 我指定的是32位，而非64位
    char *name;          // name (指针4字节) 存储的是字符串指针也就是字符串的内存地址
    unsigned int age;    // age (unsigned int 4字节)
    unsigned int gender; // gender (unsigned int 4字节)
} student;               /*无论如何赋值结构体sizeof都是12字节*/

typedef struct
{
    student *s;
} test;

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    int a = 10;
    int *aa = &a;
    int **aaa = &aa;
    printf("int a's leval 1 pointer aa: %p\n", aa);
    printf("int a's leval 2 pointer aaa: %p\n", aaa);
    printf("get int a's leval 2 pointer value *aaa: %p\n", *aaa);

    char name[] = "xiaoming";
    struct student xiaoming = {
        name,
        20,
        1};

    char name1[] = "xiaogang";
    struct student xiaogang = {
        name1,
        20,
        1};

    char name2[] = "xiaohong";
    struct student xiaohong = {
        name2,
        20,
        1};

    // --------------------------------

    // struct student xiaoming = {};
    // // name未赋值则为null ((void*)0)
    // // xiaoming.age = 20; // age未赋值则为0
    // xiaoming.gender = 1;

    struct student *ming = &xiaoming;
    char **s = &ming->name;
    // 二级指针使用*号取值是一级指针，一级指针使用*号取值是真正的值
    printf("%p\n", s);
    printf("%s\n", *s);
    printf("%p\n", *s);

    test tt;

    student *rr[] = {&xiaoming, &xiaogang, &xiaohong};

    int *ooo = rr; // rr内存地址中，存着数组的地址

    int *oop = (int *)*ooo; // 取ooo内存地址中的值，然后转换为int指针即内存地址

    student stu1 = *(student *)oop;

    printf("%x\n", oop);

    printf("%p\n", rr);

    // student *ff[] = *rr;

    tt.s = NULL;

    tt.s = *rr;

    printf("%d\n", (rr[0] - rr[1]));

    void *temp = rr[0];
    void *temp1 = rr[1];

    printf("%d\n", sizeof(*rr[0]));

    printf("%d\n", (temp - temp1));

    student *gg = temp - 2;

    system("pause");
    return 0;
}
