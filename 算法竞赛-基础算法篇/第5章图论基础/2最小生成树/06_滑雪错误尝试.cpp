#include<iostream>
#include<cstring>

using namespace std;

int n, m;
const int N = 5e3 + 10;
const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int edges[N][N];

int h[N];
int dist[M];
bool st[M];
int ret = 0, cnt = 0;
void prim()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 1; i <= n; i++)
	{
		int t = 0;
		for(int j = 1; j <= n; j++)
			if(!st[j] && dist[j] < dist[t])
				t = j;
		if(dist[t] == INF) return;
		st[t] = true;
		ret += dist[t];
		cnt++;
		for(int j = 1; j <= n; j++)
			dist[j] = min(dist[j], edges[t][j]);
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	memset(edges, 0x3f, sizeof edges);
	for(int i = 1; i <= m; i++)
	{
		int u, v, k;
		cin >> u >> v >> k;
		if(h[u] > h[v]) edges[u][v] = min(edges[u][v], k);
		else if(h[u] < h[v]) edges[v][u] = min(edges[v][u], k);
	}
	prim();
	cout << cnt << " " << ret << endl;
	return 0;
}