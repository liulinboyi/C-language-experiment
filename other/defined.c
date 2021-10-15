#include <stdio.h>
#include <stdlib.h>
//           1010 << 3 => 1010_000
//           01   << 2 => 01_00
//           3
#define TEST ((10 << 3 /*这里左移几位是为后面腾出空间*/) + (1 << 2) + 3)

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    short res = TEST; // short在32位编译中是两个字节即16位
    short res1 = (10 << 3) + (1 << 2) + 3;

    // 4: 0b100
    // 2: 0b10
    // 1: 0b1
    short temp = 0x10 | 4 | 2 | 1; // 与操作，不管当前是0或者1，和0b100与操作，结果第三位都是1

    printf("%x\n", temp);

    printf("%x\n", res);
    printf("%x\n", res1);

    system("pause");
    /* code */
    return 0;
}
