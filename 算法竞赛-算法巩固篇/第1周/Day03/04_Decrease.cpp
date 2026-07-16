#include<iostream>

using namespace std;

int n, m, k;
typedef long long LL;
const int N = 5e3 + 10;
LL f[N][N];

void insert(int x1, int x2, int y1, int y2, int d)
{
	f[x1][y1] += d;
	f[x1][y1 + 1] -= d;
	f[x2 + 1][y1] -= d;
	f[x2 + 1][y2 + 1] += d;
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		insert(x, x, y, y, z);
	}

	// for(int i = 1; i <= n; i++)
	// {
	// 	for(int j = 1; j <= n; j++)
	// 	{
	// 		cout << f[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << "first" << endl;
	LL ret = 0;
	for(int i = 1; i + k - 1 <= n; i++)
	{
		for(int j = 1; j + k - 1 <= n; j++)
		{
			ret += abs(f[i][j]);
			insert(i, i + k - 1, j, j + k - 1, -f[i][j]);
		}
	}


	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(f[i][j])
			{
				cout << -1 << endl;
				return 0;
			}
		}
	cout << ret << endl;
	return 0;
}