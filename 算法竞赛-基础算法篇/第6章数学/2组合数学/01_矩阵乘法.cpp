#include<iostream>

using namespace std;

int n, m, k;
const int N = 110;
int a[N][N], b[N][N], c[N][N];
int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			int x; cin >> x;
			a[i][j] = x;
		}
	}

	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			int y; cin >> y;
			b[i][j] = y;
		}
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k; j++)
			for(int t = 1; t <= m; t++)
				c[i][j] += a[i][t] * b[t][j];

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}