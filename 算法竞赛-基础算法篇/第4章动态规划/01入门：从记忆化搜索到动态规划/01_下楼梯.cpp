// #include<iostream>
// using namespace std;

// const int N = 1000;
// long long dp[N];
// int n;
// long long dfs(int n)
// {
// 	for(int i = 4; i <= n; i++)
// 	{
// 		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
// 	}
// 	return dp[n];
// }
// int main()
// {
// 	cin >> n;
// 	dp[1] = 1;
// 	dp[2] = 2;
// 	dp[3] = 4;
// 	cout << dfs(n) << endl;
// 	return 0;
// }



#include<iostream>
using namespace std;

const int N = 1000;
long long a, b, c, d;
int n;
long long dfs(int n)
{
	if(n == 1) return a;
	else if (n == 2) return b;
	else if(n == 3) return c;
	for(int i = 4; i <= n; i++)
	{
		d = a + b + c;
		a = b;
		b = c;
		c = d;
		//dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return d;
}
int main()
{
	cin >> n;
	a = 1;
	b = 2;
	c = 4;
	cout << dfs(n) << endl;
	return 0;
}

