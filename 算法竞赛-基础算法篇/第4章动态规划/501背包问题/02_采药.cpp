#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10010;
int t, m;
int ti[N], w[N];
int f[N][N];
//f[i][j]表示在[1, i]之前的上洞中采集草药
//时间不超过j的所有情况中的草药的最大价值
int main()
{
	cin >> t >> m;
	for(int i = 1; i <= m; i++)
		cin >> ti[i] >> w[i];
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j <= t; j++)
		{
			//不选
			f[i][j] = f[i - 1][j];
			//选
			if(j >= ti[i])
				f[i][j] = max(f[i][j], f[i - 1][j - ti[i]] + w[i]);
		}
	}

	cout << f[m][t] << endl;
	return 0;
}