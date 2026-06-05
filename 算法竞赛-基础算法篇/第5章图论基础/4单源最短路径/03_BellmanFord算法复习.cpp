//bellman-Ford算法就是对所有的边不断的进行松弛操作
//而dijkstrea算法是对每一个边找出最短的路径

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e4 + 10, INF = 2147483647;
vector<PII> edges[N];

int n, m, s;
int dist[N];

void bf()
{
	for(int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[s] = 0;
	for(int i = 1; i <= n; i++)
	{
		bool flag = false;
		for(int u = 1; u <= n; u++)
		{
			for(auto& e : edges[u])
			{
				int v = e.first, w = e.second;
				//松弛操作
				if(dist[u] != INF && dist[u] + w  < dist[v])
				{
					dist[v] = dist[u] + w;
					flag = true;
				}
			}
		}
		if(!flag) break;
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
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({b, c});
	}

	bf();
	return 0;
}