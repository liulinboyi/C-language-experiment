#include <stdio.h>
#include <stdlib.h>

#include <memory.h>
#define PSGE_SIZE 4096

struct student
{
    char *name;          // name
    unsigned int age;    // age
    unsigned int gender; // gender
};

void foo(void);

void foo(void)
{
    void *p = malloc(PSGE_SIZE);
    printf("0x%x\n", PSGE_SIZE);
    memset(p, 0, PSGE_SIZE);

    for (int i = 0; i < 13; i++)
    {
        printf("0x%x\n", *(int *)((unsigned int)p + i));
    }

    struct student *s = (struct student *)p;

    printf("%x\n", sizeof(*s));
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
