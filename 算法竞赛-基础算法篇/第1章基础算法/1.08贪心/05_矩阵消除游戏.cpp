#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long LL;
const int N = 20;
int n, m, k;
LL a[N][N];
LL col[N];

int calc(int x)
{
    int cnt = 0;
    while(x)
    {
        x -= x & (-x);
        cnt++;
    }
    return cnt;
}

bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    
    int ret = 0;
    for(int st= 0; st < (1 << n); st++)
    {
        int cnt = calc(st);
        if(cnt > k) continue;
        
        
        memset(col, 0, sizeof(col));
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((st >> i) & 1) sum += a[i][j];
                else col[j] += a[i][j];
            }
        }
        sort(col, col + m, cmp);
        for(int i = 0; i < min(k - cnt, m); i++) 
            sum += col[i];
        ret = max(ret, sum);
    }
    cout << ret << endl;
    return 0;
}