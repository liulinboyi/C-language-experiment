#include <stdio.h>
#define Max_Size 100

typedef int EleType;
// 线性表静态定义
typedef struct
{
    EleType data[Max_Size];
    int length;
} Sqlist;

// 线性表动态定义
typedef struct
{
    EleType *elem; // 基地址 在程序运行过程中分配空间
    int length;
} Sqlistd;

/**
 * 测试
 */
void test()
{
    // 静态
    Sqlist Mysqlist;
    Mysqlist.length = 0;
    for (int i = 0; i < 10; i++)
    {
        Mysqlist.data[i] = i;
        Mysqlist.length++;
    }

    //动态
    Sqlistd L;
    EleType arr[Max_Size];
    L.elem = arr;
    L.length = 0;
}

/**
 * 初始化
 */
bool initList(Sqlistd &L /*引用参数，在这个函数中做的所有改变，出了这个函数后，仍然是有效的，不加引用参数，相当于把实参复制了一份*/)
{
    L.elem = new EleType[Max_Size];
    if (!L.elem)
    { // 程序可能在小内存设备上运行，养成好习惯，需要判断程序是否运行成功
        // 分配失败
        return false;
    }
    else
    {
        L.length = 0;
        return true;
    }
}

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    // test();

    Sqlistd L;
    bool res = initList(L);
    if(res) {
        printf("init ok");
    } else {
        printf("init failed");
    }
    printf("ok");
    return 0;
}
