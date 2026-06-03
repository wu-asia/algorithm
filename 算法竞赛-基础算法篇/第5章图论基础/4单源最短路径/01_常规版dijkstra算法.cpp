//dijkstra算法

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
const int N = 1e4 + 10, INF = 2147483647;

typedef pair<int, int> PII;

int n, m, s;
//n表示点的个数
//m表示有向边的个数
//s表示出发点的编号
vector<PII> edges[N];

int dist[N];
bool st[N];

void dijkstra()
{
	//初始化
	for(int i = 0; i <= n; i++)
		dist[i] = INF;
	dist[s] = 0;
	for(int i = 1; i < n; i++)
	{
		//1.找出没有确定最短路的点中，当前最短路最小点
		int a = 0;
		for(int j = 1; j <= n; j++)
			if(!st[j] && dist[j] < dist[a])
				a = j;

		//2.打上标记，然后松弛操作
		st[a] = true;
		for(auto& t : edges[a])
		{
			int b = t.first, c = t.second;
			if(dist[a] + c < dist[b])
			{
				dist[b] = dist[a] + c;
			}
		}
	}

	for(int i = 1; i <= n; i++)
		cout << dist[i] << " ";
	cout << endl;
}
int main()
{
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({v, w});
	}
	dijkstra();
	return 0;
}