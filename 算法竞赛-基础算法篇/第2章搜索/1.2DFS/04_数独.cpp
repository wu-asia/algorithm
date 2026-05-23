#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10;
int n = 9;
int a[N][N];
bool row[N][N], col[N][N], st[N][N][N];

bool dfs(int i, int j)
{
	if(j == n)
	{
		i++;
		j = 0;
	}
	if(i == n)
	{
		return true;
	}
	if(a[i][j]) return dfs(i, j + 1);
	for(int x = 1; x <= 9; x++)
	{
		if(row[i][x] || col[j][x] || st[i / 3][j / 3][x])
			continue;
		row[i][x] = col[j][x] = st[i / 3][j / 3][x] = true;
		a[i][j] = x;
		if(dfs(i, j + 1)) return true;
		row[i][x] = col[j][x] = st[i / 3][j / 3][x] = false;
		a[i][j] = 0;
	}
	return false;
}
int main()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			int x = a[i][j];
			if(x)
			{
				row[i][x] = true;
				col[j][x] = true;
				st[i / 3][j / 3][x] = true;
			}
		}
	}

	dfs(0, 0);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}