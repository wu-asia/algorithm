#include<iostream>

using namespace std;
int n = 9;
const int N = 15;
int a[N][N];
bool row[N][N], col[N][N], st[N][N][N];
//row 是行的[行号][元素], col 是列的[列号][元素],
//st 是小格子的[第i个][第j个][元素]

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
				row[i][x] = col[j][x] = st[i / 3][j / 3][x] = true;
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