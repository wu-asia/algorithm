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
int f[M];
//f[i][j]表示的是从[1, i]中选出的重量不超过j的物品所有情况中价值最大的情形

int main()
{
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> w[i] >> v[i];
    for(int i = 1; i <= n; i++)
        for(int j = t; j >= 0; j--)
            for(int k = 0; k <= x[i] && k * w[i] <= j; k++)
                    f[j] = max(f[j], f[j - k * w[i]] + k * v[i]);
    cout << f[t] << endl;
    return 0;
}