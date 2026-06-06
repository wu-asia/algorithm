#include<iostream>
using namespace std;

typedef long long LL;
const int N = 110;
const int M = 1e4 + 10;
int n, m;
LL a[M];
LL f[N][N];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> f[i][j];

	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	LL ret = 0;
	for(int i = 1; i < m; i++)
		ret += f[a[i]][a[i + 1]];

	cout << ret << endl;
	return 0;
}