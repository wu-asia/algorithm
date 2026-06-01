#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110;
const int M = 1e3 + 10;
const int L = 1e3 + 10;
int n, m, x;
int a[N], b[N], c[N];
//n表示人选数
//m表示探查间谍能力(sum(b[i]) <= m)
//x钱的数目
int f[M][L];
//f[i][j][k]伪装能力不超过j，消费钱不超过k能获取的最多情报
int main()
{
	cin >> n >> m >> x;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = m; j >= b[i]; j--)
		{
			for(int k = x; k >= c[i]; k--)
			{
					f[j][k] = max(f[j][k], f[j - b[i]][k - c[i]] + a[i]);
			}
		}
	}
	cout << f[m][x] << endl;
	return 0;
}