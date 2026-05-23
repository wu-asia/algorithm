#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
LL a[N];
LL dp[N];
int n;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		dp[i] = a[i] + dp[i - 1];
	LL ans = LLONG_MIN;
	LL min_pre = dp[0];
	for(int i = 1; i <= n; i++)
	{
		ans = max(ans, dp[i] - min_pre);
		min_pre = min(min_pre, dp[i]);
	}
	cout << ans << endl;
	return 0;
}