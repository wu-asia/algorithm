#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<cstring>

using namespace std;
int n, m, s;
const int N = 2e5 + 10;

typedef pair<int, int> PII;

vector<PII> edges[N];
// 小根堆
priority_queue<PII, vector<PII>, greater<PII>> heap;
int dist[N];
bool st[N];

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;
	heap.push({0, s});
	while(heap.size())
	{
		auto t = heap.top();
		heap.pop();

		int x = t.second;
		if(st[x]) continue;
		st[x] = true;
		for(auto e : edges[x])
		{
			// x->b is c
			int b = e.first, c = e.second;
			if(dist[b] > dist[x] + c) 
			{
				dist[b] = dist[x] + c;
				heap.push({dist[b], b});
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