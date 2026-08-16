#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 510;
int n, m;
int a[N][N], f[N][N];
int main()
{
    cin >> n >> m;
    memset(f, 0x3f, sizeof f);
    f[0][1] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            f[i][j] = a[i][j] + min(f[i - 1][j], f[i][j - 1]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}