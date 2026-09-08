#include<iostream>
#include<vector>


using namespace std;
const int N = 1e5 + 10;
const int INF = 2147483647;
typedef pair<int, int> PII;

int n, m, s;

int dist[N];
vector<PII> edges[N];

void bf()
{
	for(int i = 0; i <= n; i++)
		dist[i] = INF;
	dist[s] = 0;
	bool flag;
	for(int i = 1; i <= n; i++)
	{
		flag = false;
		for(int j = 1; j <= n; j++)
		{
			if(dist[j] == INF) continue;
			for(auto e : edges[j])
			{
				int b = e.first, c = e.second;
				//j->b is c;
				if(dist[b] > dist[j] + c)
				{
					dist[b] = dist[j] + c;
					flag = true;
				}
			}
		}
		if(flag == false) break;
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

	bf();
	return 0;
}