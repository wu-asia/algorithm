#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

const int N = 2e5 + 10;
typedef long long LL;
LL a[N], dp[N];
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i] = dp[i - 1] + a[i];
	}
	LL max_dp = LLONG_MIN;
	LL min_pre = dp[0];
	for(int i = 1; i <= n; i++)
	{
		max_dp = max(max_dp, dp[i] - min_pre);
		min_pre = min(min_pre, dp[i]);
	}
	cout << max_dp << endl;
	return 0;
}