#include<iostream>
#include<cstring>

using namespace std;

const int N = 5010;
const int INF = 0x3f3f3f3f;

int edges[N][N];
int dist[N];
bool st[N];
int n, m;

int prim()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		//找出最短距离
		int t = 0;
		for(int j = 1; j <= n; j++)
			if(!st[j] && dist[j] < dist[t])
				t = j;
		//判断是否是连通图
		if(dist[t] == INF) return INF;

		st[t] = true;
		ret += dist[t];
		for(int j = 1; j <= n; j++)
			dist[j] = min(dist[j], edges[t][j]);
	}
	return ret;
}
int main()
{
	cin >> n >> m;
	memset(edges, 0x3f, sizeof edges);
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edges[x][y] = edges[y][x] = min(edges[x][y], z);
	}

	int ret = prim();
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	return 0;
}