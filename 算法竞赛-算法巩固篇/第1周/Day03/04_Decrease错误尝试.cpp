#include<iostream>
#include<cmath>

using namespace std;

typedef long long LL;
const int N = 5e3 + 10;
int n, m, k;
LL a[N][N];

void operate(int x, int y, int k, int d)
{
	for(int i = x; i <= x + k - 1; i++)
	{
		for(int j = y; j <= y + k - 1; j++)
		{
			a[i][j] += d;
		}
	}
}

bool iszero(int x, int y, int k)
{
	for(int i = x; i <= x + k - 1; i++)
	{
		for(int j = y; j <= y + k - 1; j++)
		{
			if(a[i][j] != 0)
				return false;
		}
	}
	return true;
}
int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		a[x][y] = z;
	}
	bool flag = true;
	int cnt = 0;
	for(int i = 1; i + k - 1 <= n; i++)
	{
		for(int j = 1; j + k - 1 <= n; j++)
		{
			int d = -a[i][j];
			if(d == 0) continue;
			cnt += (int)abs(a[i][j]);
			operate(i, j, k, d);
			if(j + k - 1 == n && !iszero(i, j, k))
			{
				flag = false;
			}
		}
	}
	if(flag)
		cout << cnt << endl;
	else
		cout << -1 << endl;
	return 0;
}