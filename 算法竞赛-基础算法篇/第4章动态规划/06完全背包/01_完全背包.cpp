#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e3 +  10;

int v[N], w[N];
int f[N][N];
int n, m;
//f[i][j]表示的是从[1, i]中选择物品，是的物品的体积不超过j的最大价值
//f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i], f[i - 1][j - 2 * v[i]] + 2 * w[i], f[i - 1][j - 3 * v[i]] + 3 * v[i], ...)
//f[i][j - v[i]] = max(f[i - 1][j - v[i]], f[i - 1][j - 2 * v[i]] + v[i], f[i - 1][j - 3 * v[i]] + 2 * v[i], ...)
//令x = f[i - 1][j - v[i]] + w[i], f[i - 1][j - 2 * v[i]] + 2 * w[i], f[i - 1][j - 3 * v[i]] + 3 * v[i], ...
//所以f[i][j - v[i]] = x + w[i];
//所以f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    f[0][0] = 0;
    //f[0][0]表示0次操作得到的体积是0的价值(即为0)
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if(j >= v[i])
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    }
    cout << f[n][m] << endl;
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if(j >= v[i])
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    }
//     for(int i = 0; i <= n; i++)
//     {
//         for(int j = 0; j <= m; j++)
//         {
//             cout << f[i][j] << " ";
//         }
//         cout << endl;
//     }
    if(f[n][m] < 0) cout << 0 << endl;
    else cout << f[n][m] << endl;
    
    return 0;
}