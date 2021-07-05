// 这是一个调试测试文件，您可以直接运行检测配置是否生效
// 若配置任然无法调试，请查阅README_inProject.md

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;

void call()
{
    printf("哈哈");
}

int main()
{
    // printf("Congratulasions! It works!\n");
    int arr[] = {99, 15, 100, 888, 252};
    // int *p = arr;
    printf("0x%p\n", arr);
    // uint64_t a = ((uint64_t) ((uint32_t) arr << 16));
    uint64_t a = (((uint64_t)(uint32_t)arr));
    uint64_t b = a << 16;

    // void* calls[10];
    // calls[0] = &call;
    printf("&call: 0x%p\n", call);

    char *aa = "abc";
    void *bb = aa;
    char *dd = bb;
    aa[0] = 'd';
    *dd++; // 修改*dd
    printf("bb:%p\n", bb);
    printf("aa[0](c):%c\n", aa[0]); // 相当于汇编寻址
    printf("aa(p):%p\n", aa);
    printf("aa:%s\n", aa);
    printf("dd:%s\n", dd);
    printf("dd(p):%p\n",dd);
    printf("dd(p):%c\n",*dd);
    printf("&dd(p):%p\n",&dd);
    printf("*&dd(p):%p\n",*&dd);

    void *p = &dd;
    void *pp = &p;
    void *ppp = &pp;
    printf("&&dd(p):%p\n",pp);
    printf("&&&dd(p):%p\n",ppp);

    char cc[] = "hello";

    printf("%s\n", cc);

    for (int i = 0; i <= 5; i++)
    {
        printf("%c\n", cc[i]);
    }

    printf("%lld\n", a);
    printf("%lld\n", b);

    char *ch = "你好";
    printf("你好ch:%s",ch);
    system("pause");
    return 0;
}