
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N], f[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= v[i]; j--)
        {
            //不选i这个位置的物品
                f[j] = max(f[j], w[i] + f[j - v[i]]);
        }
    }
    cout << f[m] << endl;
    
    memset(f, -0x3f, sizeof f);
    f[0] = 0;//表示零次操作时且总体积是零时，价值也为零
    //但是在零次操作时总体积不为零的位置就是不合法的地方，可以直接复制为负无穷，
    //在后续使用到这些格子的时候，是在负无穷上做加法，所以只要判断是否为正数，为负数则为非法
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= v[i]; j--)
        {
                f[j] = max(f[j], w[i] + f[j - v[i]]);
        }
    }
    if(f[m] < 0) cout << 0 << endl;
    else cout << f[m] << endl;
    return 0;
}