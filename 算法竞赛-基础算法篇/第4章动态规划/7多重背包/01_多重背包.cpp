#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110;
const int M = 2e3 + 10;
int n, t;
int x[N], w[N], v[N];
//x表示个数
//w表示重量
//v表示价值
int f[N][M];
//f[i][j]表示的是从[1, i]中选出的重量不超过j的物品所有情况中价值最大的情形

int main()
{
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> w[i] >> v[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= t; j++)
        {
            for(int k = 0; k <= x[i]; k++)
            {
                if(j - k * w[i] >= 0)
                    f[i][j] = max(f[i][j], f[i - 1][j - k * w[i]] + k * v[i]);
            }
        }
    }
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= t; j++)
    //     {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << f[n][t] << endl;
    return 0;
}