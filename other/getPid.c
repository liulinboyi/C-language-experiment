// #include <stdio.h>
// #include <stdlib.h>

// // #include <iostream>
// // #include <string>
// // #include <ctime>
// // #include <thread>
// // #include < Windows.h>
// #include <processthreadsapi.h>
// #include <tlhelp32.h>

// // #include <cstdio>
// #include <windows.h>
// #include <tlhelp32.h>

// DWORD getPid(char *name)
// {
//     DWORD pid;
//     PROCESSENTRY32 entry;
//     entry.dwSize = sizeof(PROCESSENTRY32);

//     HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

//     if (Process32First(snapshot, &entry) == TRUE)
//     {
//         while (Process32Next(snapshot, &entry) == TRUE)
//         {
//             if (entry.szExeFile == name)
//             {
//                 HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
//                 pid = GetProcessId(hProcess);
//                 //std::cout << "pid = " << pid << std::endl;
//                 // Do stuff..
//                 CloseHandle(hProcess);
//             }
//         }
//     }
//     CloseHandle(snapshot);
//     return pid;
// }

// int main(int argc, char const *argv[])
// {
//     (void)argc;
//     (void)argv;

//     char *name = "Microsoft Edge";
//     DWORD pid = getPid(name);
//     printf("%ld\n", pid);
//     return 0;
// }

// #include <cstdio>

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tlhelp32.h>

int main(int argc, char const *argv[])
{
    DWORD pid;
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {
            printf("%s\n", entry.szExeFile);
            if (stricmp(entry.szExeFile, "mychrome.exe") == 0)
            {
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
                pid = GetProcessId(hProcess);
                // Do stuff..

                CloseHandle(hProcess);
            }
        }
    }

    CloseHandle(snapshot);

    system("pause");

    return 0;
}
