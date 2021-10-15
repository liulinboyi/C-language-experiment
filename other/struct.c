#include <stdio.h>
#include <stdlib.h>

#include <memory.h>

struct student generate(char name[], int age, int gender);
void foo(void);
struct student
{
    // 我指定的是32位，而非64位
    char *name;          // name (指针4字节) 存储的是字符串指针也就是字符串的内存地址
    unsigned int age;    // age (unsigned int 4字节)
    unsigned int gender; // gender (unsigned int 4字节)
};                       /*无论如何赋值结构体sizeof都是12字节*/

struct student generate(char name[], int age, int gender)
{
    char *ming = name;
    struct student xiaoming = {
        ming,
        age,
        gender};
    /*
    访问结构体成员的两种方法是“结构体变量.成员”和“结构体指针变量->成员”。
    它们的访问原理是“结构体变量的地址+成员的偏移量”，这种寻址方式相当于
    “基址+变址”，其中“结构体变量的地址”相当于基址，“成员的偏移量”相当于
    变址，可以近似认为访问结构体成员的方法等效于“基址->变址”，结构体成员
    的地址等于“&（基址->变址）”。

    倘若令基址的值等于0，&(gender)不就等于偏移量n了吗。
    */
    //直接获得结构变量的偏移量
    int offset = (int)&(((struct student *)0)->name);
    printf("name,offset:%d\n", offset);
    offset = (int)&(((struct student *)0)->age);
    printf("age,offset:%d\n", offset);
    offset = (int)&(((struct student *)0)->gender);
    printf("gender,offset:%d\n", offset);

    printf("%s %d\n", name, sizeof(xiaoming));
    printf("%d\n", *(unsigned int *)((unsigned int)&xiaoming + 4)); // 骚操作，拆解
    // 目的是取结构体的第二个结构变量
    // 1. &xiaoming 取结构体的指针即内存地址，起始内存地址
    // 2. (unsigned int)&xiaoming 类型转换，方便加步长来寻址，如同汇编
    // 3. (unsigned int)&xiaoming + 4 加上步长来寻址，步长位字节。这里是加上4字节，因为第一个结构体变量长度就是4字节，加上这个长度步长，跳过第一个结构体变量。
    // 4. (unsigned int *)((unsigned int)&xiaoming + 4)) 得到第二个结构体变量内存地址后，类型转换为(unsigned int *)的指针
    // 5. *(unsigned int *)((unsigned int)&xiaoming + 4)) 最后取指针地址，得到第二个结构体变量
    return xiaoming;
}

void foo(void)
{
    // char n[] = "哈哈";
    printf("sizeof struct student %d\n",sizeof(struct student));
    generate("xiaoming", 16, 1);
    generate("xiaoli", 18, 1);
    generate("hahahahahahhahahahahahahahahahahahahahahhahaha", 20, 1);
    generate("hello my name is xiaoliu", 120, 1);
}

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    printf("struct\n");
    foo();
    system("pause");
    return 0;
}
