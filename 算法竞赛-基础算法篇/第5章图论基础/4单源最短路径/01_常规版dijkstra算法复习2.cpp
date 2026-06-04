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

vector<PII> edges[M];
int n, m, s;

void dijkstra()
{
	for(int i = 0; i <= n; i++)
		dist[i] = INF;
	//初始化起点
	dist[s] = 0;
	for(int i = 1; i <= n; i++)
	{
		int a = 0;
		for(int j = 1; j <= n; j++)
			if(!st[j] && dist[j] < dist[a])
				a = j;

		st[a] = true;
		for(auto& e : edges[a])
		{
			int b = e.first, c = e.second;
			if(dist[b] > dist[a] + c)
				dist[b] = dist[a] + c;
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