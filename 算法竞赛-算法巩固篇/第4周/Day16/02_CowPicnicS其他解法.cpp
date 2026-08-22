#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>

using namespace std;

int k, n, m;

const int N = 1e3 + 10;
int edge[N][N];
int c[N];
bool st[N];
int path[N][N];
int flag;

void dfs(int x)
{
	st[x] = true;
	for(int i = 1; i <= n; i++)
	{
		if(edge[x][i] == 1 && !st[i])
		{
			path[flag][i] = 1;
			dfs(i);
		}
	}
}


int main()
{
	cin >> k >> n >> m;
	for(int i = 1; i <= k; i++)
		cin >> c[i];
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		edge[x][y] = 1;
	}
	for(int i = 1; i <= n; i++)
		path[i][i] = 1;
	for(int i = 1; i <= k; i++)
	{
		flag = c[i];
		memset(st, 0, sizeof st);
		dfs(c[i]);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int ret = 1;
		for(int j = 1; j <= k; j++)
		{
			ret = ret * path[c[j]][i];
		}
		if(ret == 1)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}