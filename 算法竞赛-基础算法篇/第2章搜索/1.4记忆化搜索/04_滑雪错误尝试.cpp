#include<iostream>
using namespace std;

const int N = 110;
int a[N][N];
int R, C;
int cnt, ret;
int f[N][N];
void dfs(int row, int col)
{
	if(a[row][col] == 1 || (a[row][col] < a[row][col + 1] && a[row]))
	{
		return;
	}
	if(a[row][col + 1] && a[row][col] > a[row][col + 1])
	{
		cnt++;
		ret = max(cnt, ret);
		dfs(row, col + 1);
		f[row][col] = ret;
	}
	else if(a[row + 1][col] && a[row][col] > a[row + 1][col])
	{
		cnt++;
		ret = max(cnt, ret);
		dfs(row + 1, col);
		f[row][col] = ret;
	}
}
int main()
{
	cin >> R >> C;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			cin >> a[i][j];
		}
	}
	return 0;
}