#include<iostream>
#include<cstring>

using namespace std;

const int N = 5010;
int n, m;
const int INF = 0x3f3f3f3f;
int edges[N][N];
int dist[N];
bool st[N];

int prim()
{
	//初始化dist
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	int ret = 0;
	for(int i = 1; i <= n; i++) //循环加入n个节点
	{
		int t = 0;
		for(int j = 1; j <= n; j++)
		{
			if(!st[j] && dist[j] < dist[t])
				t = j;
		}
		//判断是否连通
		if(dist[t] == INF) return INF;
		ret += dist[t];
		st[t] = true;

		for(int j = 1; j <= n; j++)
		{
			dist[j] = min(dist[j], edges[t][j]);
		}	
	}
	return ret;
}
int main()
{
	cin >> n >> m;
	memset(edges, 0x3f, sizeof edges);
	for(int j = 1; j <= m; j++)
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