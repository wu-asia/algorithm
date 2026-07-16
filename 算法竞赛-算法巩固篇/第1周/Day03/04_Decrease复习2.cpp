#include<iostream>
using namespace std;
typedef long long LL;
const int N = 5010;

int n, m, k;
LL f[N][N];
LL op[N][N];

void insert(LL arr[][N], int x1, int y1, int x2, int y2, LL val)
{
    arr[x1][y1] += val;
    arr[x1][y2 + 1] -= val;
    arr[x2 + 1][y1] -= val;
    arr[x2 + 1][y2 + 1] += val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        insert(f, x, y, x, y, z);
    }

    //算出初始网格的值
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }

    LL ret = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            //计算op数组的前缀和，得到当前位置被减去的值
            op[i][j] += op[i - 1][j] + op[i][j - 1] - op[i - 1][j - 1];
            LL now = f[i][j] - op[i][j];
            if(now == 0) continue;
            int nx = i + k - 1;
            int ny = j + k - 1;
            if(nx > n || ny > n)
            {
                cout << -1 << endl;
                return 0;
            }
            ret += abs(now);
            insert(op, i, j, nx, ny, now);
        }
    }
    cout << ret << endl;
    return 0;
}