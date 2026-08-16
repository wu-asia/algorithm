#include<iostream>
#include<cstring>
using namespace std;

const int N = 110, M = 1e4 + 10;
int t, n, m;
//t天数
//n数量
//m金币数
int p[N][N];
//p[i][j]表示第i天第j个纪念品的价格
int f[M];

//v[i]表示的是某一天的纪念品的价格，而w[i]表示后一天的价格
//profit[i] = w[i] - v[i]可以表示第i件纪念品可以盈利的情况
int solve(int v[], int w[], int m)
{
	memset(f, 0, sizeof f);
	for(int i = 1; i <= n; i++)
	{
		for(int j = v[i]; j <= m; j++)
		{
				f[j] = max(f[j], f[j - v[i]] + (w[i] - v[i]));
		}
	}
	//函数的返回值是这一天过后的金币数，即原本的金币加上盈利的金币
	return m + f[m];
}
int main()
{
	cin >> t >> n >> m;
	for(int i = 1; i <= t; i++)
		for(int j = 1; j <= n; j++)
			cin >> p[i][j];
	for(int i = 1; i < t; i++)
	{
		//贪心
		m = solve(p[i], p[i + 1], m);
	}
	cout << m << endl;
	return 0;
}