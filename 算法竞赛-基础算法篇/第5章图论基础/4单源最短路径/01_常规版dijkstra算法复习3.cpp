#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e4 + 10;
const int M = 5e5 + 10;
struct node
{
	int v, w;
};
vector<node> edges[N];
const int INF = 2147483647;
int n, m, s;

int dist[N];
bool st[N];

void dijkstra()
{
	for(int i = 0; i <= n; i++)
		dist[i] = INF;
	dist[s] = 0;
	for(int i = 1; i <= n; i++)
	{	
		int t = 0;
		for(int j = 1; j <= n; j++)
		{
			if(!st[j] && dist[j] < dist[t])
				t = j;
		}
		st[t] = true;
		for(auto& e : edges[t])
		{
			int v = e.v, w = e.w;
			if(dist[t] + w < dist[v])
				dist[v] = dist[t] + w;
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