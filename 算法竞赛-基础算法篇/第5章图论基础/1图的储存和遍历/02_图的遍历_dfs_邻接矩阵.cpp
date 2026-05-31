#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N = 1010;

int n, m;
int edges[N][N];

bool st[N];
//标记哪些点已经访问过了

void dfs(int u)
{
	cout << u << endl;
	st[u] = true;

	//遍历所有孩子
	for(int v = 1; v <= n; v++)
	{
		//如果在u->v的边，并且没有遍历过
		if(edges[u][v] != -1 && !st[v])
		{
			dfs(v);
		}
	}
}


int main()
{
	memset(edges, -1, sizeof edges);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		edges[a][b] = c;
		edges[b][a] = c;
	}
}