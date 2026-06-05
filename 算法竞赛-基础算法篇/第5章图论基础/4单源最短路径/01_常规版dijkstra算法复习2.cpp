#include<iostream>
#include<vector>
#include<utility>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e4 + 10;
const int M = 5e5 + 10;
const int INF = 2147483647;
int dist[N];
bool st[N];

vector<PII> edges[N];
int n, m, s;

void dijkstra()
{
	for(int i = 0; i <= n; i++)
		dist[i] = INF;
	dist[s] = 0;

	for(int i = 1; i <= n; i++)
	{
		//找出最小节点
		int t = 0;
		for(int j = 1; j <= n; j++)
			if(!st[j] && dist[j] < dist[t])
				t = j;
		st[t] = true;

		for(auto& e : edges[t])
		{
			int a = e.first, b = e.second;
			if(dist[t] != INF && dist[t] + b < dist[a])
				dist[a] = dist[t] + b;
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