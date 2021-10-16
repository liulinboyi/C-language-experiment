#include <iostream>
#include <algorithm>
using namespace std;
#define DEBUG true

/**
 * 有一天，海盗们截获了一艘装满各种各样古董的货船，每件古董都价值连城，一旦打碎就失去了价值。
 * 虽然海盗船足够大，但载重为c，每件古董的重量为wi，海盗们绞尽脑汁要把尽可能多的宝贝装上海盗船，
 * 该怎么办呢？
 */

void solution()
{
    double tmp = 0.0;
    int ans = 0;
    int c = 30;
    int w[] = {4, 10, 7, 11, 3, 5, 15, 2};
    int n = sizeof(w) / sizeof(*w);
    sort(w, w + n);
    for (int i = 0; i < n; i++)
    {
        tmp += w[i];
        if (tmp < c)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
}

void solution1()
{
    const int N = 1000;
    double w[N], c; //古董的重量数组
    int n, m;
    cin >> m;
    while (m--)
    { //m个测试用例
        if (DEBUG)
        {
            cout << "please input Volume of ship:" << endl;
            cin >> c;
            cout << "please input Number of antiques:" << endl;
            cin >> n;
        } else {
            cin >> c >> n;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> w[i]; //输入每个物品重量
        }
        sort(w, w + n); //按古董重量升序排序
        double tmp = 0.0;
        int ans = 0; // tmp为已装载到船上的古董重量，ans为已装载的古董个数
        for (int i = 0; i < n; i++)
        {
            tmp += w[i];
            if (tmp <= c)
                ans++;
            else
                break;
        }
        cout << ans << endl;
    }
}

int main(int argc, char const *argv[])
{

    (void)argc;
    (void)argv;
    // solution();
    solution1();
    return 0;
}
