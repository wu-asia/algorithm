#include<iostream>
using namespace std;

const int N = 1e5 + 10;
typedef long long LL;
int n, m;
LL a[N], dp[N];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = dp[i - 1] + a[i];
    }
    while(m--)
    {
        int l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }
        
    return 0;
}