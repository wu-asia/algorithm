#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N], f[N][N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }
    //f[i][j]表示的是在取第i个位置时，总体积不超过j时的最大价值
    //f[i][j]表示从[1, i]中选出的物品的总体积不超过j，所取到的最大价值
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            //不选i这个位置的物品
            f[i][j] = f[i - 1][j];
            if(j >= v[i])
            {
                f[i][j] = max(f[i][j], w[i] + f[i - 1][j - v[i]]);
            }
        }
    }
    cout << f[n][m] << endl;
    
    //f[i][j]表示的是从[1, i]中选取的物品的总体积必须是j，所取得的最大值
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;//表示零次操作时且总体积是零时，价值也为零
    //但是在零次操作时总体积不为零的位置就是不合法的地方，可以直接复制为负无穷，
    //在后续使用到这些格子的时候，是在负无穷上做加法，所以只要判断是否为正数，为负数则为非法
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if(j >= v[i])
                f[i][j] = max(f[i][j], w[i] + f[i - 1][j - v[i]]);
        }
    }
    if(f[n][m] < 0) cout << 0 << endl;
    else cout << f[n][m] << endl;
    return 0;
}
