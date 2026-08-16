#include<iostream>
using namespace std;
typedef long long LL;
const int N = 20;
LL a[N][N];
LL f[N][N][N];
int t, n;
int main()
{
	cin >> n;
	while(1)
	{
		LL x, y, v;
		cin >> x >> y >> v;
		if(x == 0 && y == 0 && v == 0)
			break;
		a[x][y] = v;
	}

	//s在第一个格子时是1 + 1, 在最后一个格子是n + n
	for(int s = 2; s <= n + n; s++)
	{
		for(int i1 = 1; i1 <= n; i1++)
		{
			for(int i2 = 1; i2 <= n; i2++)
			{
				int j1 = s - i1, j2 = s - i2;
				if(j1 < 1 || j1 > n || j2 < 1 || j2 > n)
					continue;
				int t = max(max(f[s - 1][i1][i2], f[s - 1][i1 - 1][i2 - 1]),
				 max(f[s - 1][i1 - 1][i2], f[s - 1][i1][i2 - 1]));
				if(i1 == i2)
				{
					f[s][i1][i2] = t + a[i1][s - i1];
				}
				else
				{
					f[s][i1][i2] = t + a[i1][s - i1] + a[i2][s - i2];
				}

			}
		}
	}
	cout << f[n + n][n][n] << endl;
	return 0;
}