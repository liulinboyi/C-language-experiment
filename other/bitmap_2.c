#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//定义每个Byte中有8个Bit位
#include <memory.h>
#define BYTESIZE 8

#ifndef _LIB_STDINT_H
#define _LIB_STDINT_H

typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed int int32_t;
typedef signed long long int int64_t;

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;

#endif

/*
https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/06.07.md
*/

#define BITMAP_MASK 1 // 宏BITMAP_MASK其值为1，用来在位图中逐位判断，主要就是通过按位与‘&’来判断相应位是否为1。

// struct bitmap中只定义了两个成员：位图的指针bits和位图的字节长度btmp_bytes_len。
struct bitmap
{
    uint32_t btmp_bytes_len;
    /* 在遍历位图时,整体上以字节为单位,细节上是以位为单位,所以此处位图的指针必须是单字节 */
    uint8_t *bits; // *指针就是内存地址，这里声明的意思是指针的类型是uint8_t，仍然是内存地址。不同指针类型，在地址处取值时(*指针)的方法和长度不同而已
};

void SetBit(char *p, int posi);
bool bitmap_scan_test(struct bitmap *btmp, uint32_t bit_idx);
void printbit(char *pBuffer);
void BitMapSortDemo(void);
void BitMapSortDemo1(void);

/* 判断bit_idx位是否为1,若为1则返回true，否则返回false */
// bitmap_scan_test函数接受两个参数，分别是位图指针btmp和位索引bit_idx。其功能是判断位图btmp中的第bit_idx位是否为1，若为1，则返回true，否则返回false。
// 如果bit_idx为10的话，byte_idx为1，bit_odd为2，字节索引1中的位1
bool bitmap_scan_test(struct bitmap *btmp, uint32_t bit_idx)
{
    uint32_t byte_idx = bit_idx / 8; // 向下取整用于索引数组下标
    uint32_t bit_odd = bit_idx % 8;  // 取余用于索引数组内的位
    uint8_t *bb = btmp->bits;
    printf("%c\n", *bb);
    uint8_t cc = btmp->bits[byte_idx];
    printf("%c\n", cc);
    int adds = btmp->bits[byte_idx];
    char *dds = (char *)&adds; // 先转成int*，然后转换为char* 指针也有类型，主要是为了从内存中取值用做依据
    printbit(dds);
    uint32_t left = btmp->bits[byte_idx];
    uint32_t right = (BITMAP_MASK << (8 - bit_odd - 1));
    printbit((char *)&left);
    printbit((char *)&right);
    printf("left: %d,right: %d\n", left, right);
    return (left & right);
}

// 打印一字节二进制
void printbit(char *pBuffer)
{
    int res = *pBuffer;
    int count = 7;
    printf("byte:");
    for (int i = 0; i < 8; i++)
    {
        printf("%d", (res & (0x01 << count)) == 0 ? 0 : 1);
        count--;
    }
    printf("\n");
}

void SetBit(char *p, int posi)
{
    p = p + (posi / BYTESIZE);
    *p = *p | (0x01 << (posi % BYTESIZE)); //将该Bit位赋值1，或操作会保留，位为1的二进制位
    return;
}

void BitMapSortDemo(void)
{
    //为了简单起见，我们不考虑负数
    int num[] = {4, 7, 2, 5, 3};

    //BufferLen这个值是根据待排序的数据中最大值确定的
    //待排序中的最大值是14，因此只需要2个Bytes(16个Bit)
    //就可以了。
    const int BufferLen = 1;
    char p[BufferLen];
    char *pBuffer = p;

    //要将所有的Bit位置为0，否则结果不可预知。
    memset(pBuffer, 0, BufferLen);
    for (int i = 0; i < 5; i++)
    {
        //首先将相应Bit位上置为1
        SetBit(pBuffer, num[i]);
    }

    uint8_t *u = (uint8_t *)pBuffer;

    struct bitmap map = {
        1,
        u};

    bool r = bitmap_scan_test(&map, 6);
    printf("%d\n", r);
    // 0b10111100
    // 0b00000001

    //输出排序结果
    for (int i = 0; i < BufferLen; i++) //每次处理一个字节(Byte)
    {
        printbit(pBuffer);
        for (int j = 0; j < BYTESIZE; j++) //处理该字节中的每个Bit位
        {
            //判断该位上是否是1，进行输出，这里的判断比较笨。
            //首先得到该第j位的掩码（0x01＜＜j），将内存区中的
            //位和此掩码作与操作。最后判断掩码是否和处理后的
            //结果相同
            printf("*pBuffer:%c\n", *pBuffer);
            printf("*pBuffer & (0x01 << j):%d\n", (*pBuffer & (0x01 << j)));
            // printf("\n");
            printf("(0x01 << j):%d\n", (0x01 << j));
            printf("\n");
            // 0b00000001 & 0b00000001 == 0b00000001

            //  *pBuffer    0x01 << j     0x01 << j  j
            // 0b10111100 & 0b00000001 == 0b00000001 0
            // 0b10111100 & 0b00000010 == 0b00000010 1
            // 0b10111100 & 0b00000100 == 0b00000100 2
            // 0b10111100 & 0b00001000 == 0b00001000 3
            if ((*pBuffer & (0x01 << j)) == (0x01 << j))
            {
                printf("%d ", i * BYTESIZE + j);
            }
        }
        pBuffer++;
    }
}

void BitMapSortDemo1(void)
{
    //为了简单起见，我们不考虑负数
    int num[] = {3, 5, 2, 10, 6, 12, 8, 14, 9};
    int len = sizeof(num) / sizeof(num[0]);
    printf("%d", len);

    //BufferLen这个值是根据待排序的数据中最大值确定的
    //待排序中的最大值是14，因此只需要2个Bytes(16个Bit)
    //就可以了。
    const int BufferLen = 2;
    char p[BufferLen];
    char *pBuffer = p;

    //要将所有的Bit位置为0，否则结果不可预知。
    memset(pBuffer, 0, BufferLen);
    for (int i = 0; i < len; i++)
    {
        //首先将相应Bit位上置为1
        SetBit(pBuffer, num[i]);
    }

    // uint8_t *u = (uint8_t *)pBuffer; // 指针也有类型，主要是为了从内存中取值用做依据
    uint8_t *u = (uint8_t *)pBuffer;
    printf("%p\n", u);
    printf("%c\n", *u);

    struct bitmap map = {
        2,
        u};

    bool r = bitmap_scan_test(&map, 11);
    printf("%d\n", r);
    // 0b10111100
    // 0b00000001

    //输出排序结果
    for (int i = 0; i < BufferLen; i++) //每次处理一个字节(Byte)
    {
        printbit(pBuffer);
        for (int j = 0; j < BYTESIZE; j++) //处理该字节中的每个Bit位
        {
            //判断该位上是否是1，进行输出，这里的判断比较笨。
            //首先得到该第j位的掩码（0x01＜＜j），将内存区中的
            //位和此掩码作与操作。最后判断掩码是否和处理后的
            //结果相同
            printf("*pBuffer:%c\n", *pBuffer);
            printf("*pBuffer & (0x01 << j):%d\n", (*pBuffer & (0x01 << j)));
            // printf("\n");
            printf("(0x01 << j):%d\n", (0x01 << j));
            printf("\n");
            // 0b00000001 & 0b00000001 == 0b00000001

            //  *pBuffer    0x01 << j     0x01 << j  j
            // 0b10111100 & 0b00000001 == 0b00000001 0
            // 0b10111100 & 0b00000010 == 0b00000010 1
            // 0b10111100 & 0b00000100 == 0b00000100 2
            // 0b10111100 & 0b00001000 == 0b00001000 3
            if ((*pBuffer & (0x01 << j)) == (0x01 << j))
            {
                printf("---%d---\n", i * BYTESIZE + j);
            }
        }
        pBuffer++;
    }
}

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;
    // BitMapSortDemo1();
    BitMapSortDemo();
    system("pause");
    return 0;
}
