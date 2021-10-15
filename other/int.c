#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(void);
void foo(void)
{
    unsigned int b = -1;
    int a = -1;
    printf("%d %d\n", a, b);
}
int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    foo();
    system("pause");
    return 0;
}
