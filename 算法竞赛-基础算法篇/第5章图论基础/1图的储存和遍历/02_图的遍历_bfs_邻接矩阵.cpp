#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N = 1010;

int n, m;
int edges[N][N];
bool st[N];
void bfs(int u)
{
	queue<int> q;
	q.push(u);
	st[u] = true;
	while(q.size())
	{
		auto a = q.front();
		q.pop();
		cout << a << endl;
		for(int b = 1; b <= n; b++)
		{
			if(edges[a][b] != -1 && !st[b])
			{
				q.push(b);
				st[b] = true;
			}
		}
	}
}
int main()
{
	memset(edges, -1, sizeof edges);

	cin >> n >> m;
	//n表示的是顶点的个数，m表示的是边的个数
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		//a - b有一条边，权值为c
		edges[a][b] = c;
		edges[b][a] = c;
	}
	return 0;
}