#include<iostream>

using namespace std;

const int N = 110;
int n, m;
char a[N][N];
int fa[N * N];
int dx[] = {0, 1, 1, 1};
int dy[] = {1, 1, 0, -1};

int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void un(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	fa[fx] = fy;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n * m; i++)
		fa[i] = i;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] != 'W') continue;
			int pos = i * m + j;
			for(int k = 0; k < 4; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if(x >= 0 && x < n && y >= 0 && y < m && a[i][j] == 'W')
				{
					if(a[x][y] == 'W')
					{
						int tmp = x * m + y;
						un(pos, tmp);
					}
				}

			}
		}
	}
	int ret = 0;
	for(int i = 0; i < n * m; i++)
	{
		int x = i / m, y = i % m;
		if(a[x][y] == 'W' && fa[i] == i)
			ret++;
	}
	cout << ret << endl;
	return 0;
}