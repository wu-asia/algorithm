#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e4 + 10;
const int INF = 2147483647;
vector<PII> edges[N];
int dist[N];
bool st[N];
int n, m, s;

void dijkstra()
{

	for(int i = 0; i <= n; i++)
		dist[i] = INF;
	dist[s] = 0;
	for(int i = 1; i < n; i++)
	{
		int t = 0;
		for(int j = 1; j <= n; j++)
		{
			if(!st[j] && dist[j] < dist[t])
				t = j;
		}
		// cout << "t is " << t << endl;
		st[t] = true;

		for(auto e : edges[t])
		{
			//t->b is c
			int b = e.first, c = e.second;
			if(dist[t] + c < dist[b])
				dist[b] = dist[t] + c;
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
		int u, v, w; cin >> u >> v >> w;
		edges[u].push_back({v, w});
	}

	dijkstra();
	return 0;
}