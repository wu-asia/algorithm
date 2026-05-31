//股票问题中，重要结论：
//任何一笔跨天的交易，都可以转化为连续的"某天买，隔天卖"的形式
#include<iostream>
#include<cstring>

using namespace std;

const int N = 110, M = 1e4 + 10;
int t, n, m;
int p[N][N];
int f[M];

//完全背包
int solve(int v[], int w[], int m)
{
	//清空数据
	memset(f, 0, sizeof f);
	for(int i = 1; i<= n; i++)
	{
		for(int j = v[i]; j <= m; j++)
		{
			f[j] = max(f[j], f[j - v[i]] + w[i] - v[i]);
		}
	}
	return m + f[m];
}
int main()
{
	cin >> t >> n >> m;
	for(int i = 1; i <= t; i ++)
		for(int j = 1; j <= n; j++)
			cin >> p[i][j];
	//贪心
	for(int i = 1; i < t; i++)
	{
		m = solve(p[i], p[i + 1], m);
	}
	cout << m << endl;
	return 0;
}