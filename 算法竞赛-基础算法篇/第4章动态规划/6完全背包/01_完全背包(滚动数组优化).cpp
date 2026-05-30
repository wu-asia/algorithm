//完全背包中的通向f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i])
//f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i], f[i - 1][j - 2 * v[i]] + 2 * w[i], f[i - 1][j - 3 * v[i]] + 3 * w[i], ...)
//确保j - k * v[i] >= 0
//f[i][j - v[i]] = max(f[i - 1][j - v[i]], f[i - 1][j - 2 * v[i]] + v[i], f[i - 1][j - 3 * v[i]] + 2 * v[i], f[i - 1][j - 4 * v[i]] + 3 * v[i], ...)
//令x = max(f[i - 1][j - v[i]] + w[i], f[i - 1][j - 2 * v[i]] + 2 * w[i], f[i - 1][j - 3 * v[i]] + 3 * w[i], ...)
//所以f[i][j] = max(f[i - 1][j], x)
//f[i][j - v[i]] + w[i] = max(f[i - 1][j - v[i]], f[i - 1][j - 2 * v[i]] + v[i], f[i - 1][j - 3 * v[i]] + 2 * v[i], f[i - 1][j - 4 * v[i]] + 3 * v[i], ...) + w[i]
// = max(f[i - 1][j - v[i]] + w[i], f[i - 1][j - 2 * v[i]] + 2 * w[i], f[i - 1][j - 3 * v[i]] + 3 * w[i], ...) = x
//所以f[i][j - v[i]] + w[i] = x;
//所以f[i][j] = max(f[i - 1][j], f[i][j - v[i]])
//因为求f[i][j]需要使用f[i][j - v[i]]
//所以滚动数组是从左向右的


#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e3 +  10;

int v[N], w[N];
int f[N];
int n, m;
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    f[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(j >= v[i])
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(j >= v[i])
                f[j] = max(f[j], f[j - v[i]] + w[i]);
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
    if(f[m] < 0) cout << 0 << endl;
    else cout << f[m] << endl;
    
    return 0;
}