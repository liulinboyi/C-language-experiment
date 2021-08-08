# undefined reference to `__stack_chk_fail'

出现这个错误，经过一番查询得出以下解决方案：

一、

一些版本的gcc编译时常会出现 undefined reference to `__stack_chk_fail'的错误，可以在makefile的CFLAGS中添加-fno-stack-protector一项。

-- [原地址](https://blog.csdn.net/cedricporter/article/details/6788390)

二、

在编译程序时klib.c中的disp_int报了该错，去网上搜了一下，在Makefile中的$(CFLAGS)后面加上-fno-stack-protector，即不需要栈保护

lib/klib.o:lib/klib.c
        $(CC) $(CFLAGS) -fno-stack-protector -o $@ $<

然后编译就可以了正常执行了

然后就自己验证了一下，将char output[16];注释掉改为char* output,编译不报错，说明问题就是由于定义数组的栈操作引起。

```c
int main()

{

    char a[16];

    return 0;

}
```

-- [原地址](https://blog.csdn.net/xiaominthere/article/details/18084865)



# 反编译调试C程序

比如test.c，首先编译时加上-g可以得到带调试信息的可执行程序
```
gcc test.c -g -o test
```
然后，在gdb中使用
```
disas main或者disas sum查看这两个函数的汇编代码
```

参考其他地址
https://stackoverflow.com/questions/4492799/undefined-reference-to-stack-chk-fail

https://bbs.csdn.net/topics/350133222

https://www.zhihu.com/question/304260625

https://www.cnblogs.com/arnoldlu/p/11630979.html

http://luodw.cc/2015/10/07/gdb/

https://blog.csdn.net/u013946356/article/details/60867761

