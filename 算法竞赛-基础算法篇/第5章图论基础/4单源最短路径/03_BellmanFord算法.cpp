//bellman-ford算法只需要经过每条边一次
//所以仅需要执行n - 1次的松弛操作
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e4 + 10, INF = 2147483647;
int n, m, s;

vector<PII> edges[N];
int dist[N];

void bf()
{
	for(int i = 0; i <= n; i++)
		dist[i] = INF;
	dist[s] = 0;
	bool flag = false;
	for(int i = 1; i < n; i++)
	{
		flag = false;
		//u表示起点
		for(int u = 1; u <= n; u++)
		{
			for(auto& t : edges[u])
			{
				int v = t.first, w = t.second;
				if(dist[u] != INF && dist[u] + w < dist[v])
				{
					dist[v] = dist[u] + w;
					flag = true;
				}
			}
		}
		if(flag == false)
			break;
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