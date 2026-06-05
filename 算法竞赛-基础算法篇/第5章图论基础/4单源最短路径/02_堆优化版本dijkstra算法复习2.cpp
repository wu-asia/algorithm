//时间复杂度是O(mlogm)
//m为边的数目
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 10;

int n, m, s;

vector<PII> edges[N];
int dist[N];
bool st[N];
//小根堆
priority_queue<PII, vector<PII>, greater<PII>> heap;
//<距离, 节点>

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);

	dist[s] = 0;
	//储存方式<距离, 节点>
	heap.push({dist[s], s});

	while(heap.size())
	{
		auto t = heap.top();
		heap.pop();
		int a = t.second;
		if(st[a]) continue;
		st[a] = true;
		for(auto& e : edges[a])
		{
			int b = e.first, c = e.second;
			//松弛操作
			if(dist[b] > dist[a] + c)
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