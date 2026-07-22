#include<iostream>

using namespace std;

int n, m;

const int N = 10;
bool st[N][N];

int ret;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int i, int j)
{
	if(i < 1 || i >= n || j < 1 || j >= m)
	{
		ret++;
		return;
	}
	st[i][j] = true;

	for(int k = 0; k < 4; k++)
	{
		int a = i + dx[k], b = j + dy[k];
		if(!st[a][b]) dfs(a, b);
	}
	
	st[i][j] = false;
}

int main()
{
	cin >> n >> m;
	//左侧
	for(int i = 1; i < n; i++)
	{
		st[i][0] = true;
		dfs(i, 1);
		st[i][0] = false;
	}
	for(int i = 1; i < m; i++)
	{
		st[0][i] = true;
		dfs(1, i);
		st[i][0] = false;
	}
	cout << ret << endl;
	return 0;
}