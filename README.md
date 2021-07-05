<!-- 这是一个Markdown文档 -->
<!-- 你可以通过VS code自带的预览功能，获得更好的阅读体验 -->
<!-- 默认快捷键为先按下Ctrl + K 再按下 V -->
# C语言实验

> 内联汇编与C语言指针

> VScode使用说明
## VScode C/C++ 开发环境使用须知
### 前言
**祝贺你！** 您已成功完成了 VScode C/C++ 开发环境的配置。这是您迈向C/C++编程世界的第一步！

在使用本工具配置的VScode开发环境，请您先**仔细阅读该说明文档**，以避免遇到无法预期的错误。

### 首次启动
* **调试前需要重新启动**，配置工具改动了环境变量，需要系统重启生效。调试无法在环境变量生效前正常工作。

* **自动或手动安装C/C++插件后**，插件仍需要下载若干内容。下载进度在VScode右下角显示。若插件工作不正常，请等待下载完毕后重试。

* **避免使用中文文件名** MinGW的调试工具**不支持中文路径或文件名**。请避免使用。

* **确保源码的文件后缀正确** 只有文件以.c或.cpp结尾时才会使配置和插件生效。
* **询问前先查看Q&A** 我已经尽己所能想出了您可能遇到的问题。请先查看[Q&A](#Q&A)，并确保自己的问题不被包含后，再来询问我。这将会节省你我的宝贵时间，并可以使问题快速、有效的解决。

### Q&A
#### Q 为什么我将源码放在工作区之外，VScode打开后不能正常调试？
#### Q 如何迁移工作区
因为调试配置保存在原来的工作区。

请用VScode打开源码所在的文件夹，并将原工作区的.vscode文件夹复制到新文件夹。

详见[什么是工作区文件夹](#什么是工作区文件夹)

#### Q 无法将“g++”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。
该错误说明MinGW编译器没有被加入到Path环境变量中。

**如果您在配置完成后未重启计算机，请先重启。**

以下步骤可以帮您排查问题。
请打开一个新的cmd窗口，输入g++。如果提示

```
无法将“g++”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。
```

则请手动安装MinGW编译器。详情请百度。

若提示内容为
```
g++: fatal error: no input files
compilation terminated.
```
则说明MinGW已经成功安装。请重启VScode或使用工具再次配置。

## 附加说明

### 什么是工作区文件夹
通过VScode打开的文件夹会被识别为一个工作区，工作区内的所有文件将会共享这个工作区配置。工作区与工作区之间的配置互不影响。

如果您需要更换存放源码的位置，**请务必复制.vscode文件夹到新目录**，否则将无法正常调试。

### .vscode文件夹
VScode 工作区配置保存在工作区下.vscode文件夹内。VScode将会依照该文件夹内的配置文件执行调试步骤。

本配置工具会自动向您选择的工作区目录下生成有关C/C++
语法检查、自动补全、调试的配置。

### 什么是编译器
简单来讲，编译器是把你写的c/cpp编程exe的工具。

作者对此方面知之甚少，详情也请百度哈

### 什么是MinGW
MinGW 提供了一套简单方便的Windows下的基于GCC 程序开发环境。MinGW 收集了一系列免费的Windows 使用的头文件和库文件；同时整合了 GNU 的工具集，特别是 GNU 程序开发工具，如经典gcc, g++, make等。

我们主要使用MinGW进行调试与编译。

### 为什么需要配置环境变量
在VScode中，大部分操作需要通过命令执行。在Windows系统中，可执行文件本身可能散布在系统的各个储存位置。Windows并不知道去哪里调用这些命令对应的文件。

环境变量记录了命令文件所在位置。若环境变量配置不正确，Windows将无法识别该命令。

## 反馈
如果该文档并没有包含到您遇到的错误情况或您想了解的内容，请通过以下方式向我反馈。
* [B站私信](https://space.bilibili.com/12263994)
* [视频评论](https://www.bilibili.com/video/av52434248)
* [Github Issue](https://github.com/SDchao/AutoVsCEnv_WPF/issues/new) **推荐**