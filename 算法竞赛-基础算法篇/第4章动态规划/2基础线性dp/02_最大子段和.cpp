#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;
const int N = 2e5 + 10;
int n;
long long a;
long long dp[N];
int main()
{
	cin >> n;
	// for(int i = 1; i <= n; i++)
	// 	cin >> a[i];
	// for(int i = 1; i <= n; i++)
	// 	dp[i] = dp[i - 1] + a[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> a;
		dp[i] = dp[i - 1] + a;
	}
	long long ret = LLONG_MIN;
	long long pre_min = dp[0];
	for(int i = 1; i <= n; i++)
	{
		ret = max(ret, dp[i] - pre_min);
		pre_min = min(pre_min, dp[i]);
	}
	cout << ret << endl;

	return 0;
}