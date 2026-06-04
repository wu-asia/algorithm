#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;
const int N = 1e5 + 10;
typedef pair<int, int> PII;
int dist[N];
bool st[N];
vector<PII> edges[N];
int n, m, s;
priority_queue<PII, vector<PII>, greater<PII>> heap;

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;
	//<距离, 节点>
	heap.push({dist[s], s});
	while(heap.size())
	{
		auto t = heap.top();
		heap.pop();
		//获取最小的节点
		int a = t.second;
		if(st[a]) continue;
		st[a] = true;
		for(auto& e : edges[a])
		{
			int b = e.first, c = e.second;
			//b为节点，c为权值
			if(dist[a] + c < dist[b])
			{
				dist[b] = dist[a] + c;
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
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({b, c});
	}
	dijkstra();
	return 0;
}