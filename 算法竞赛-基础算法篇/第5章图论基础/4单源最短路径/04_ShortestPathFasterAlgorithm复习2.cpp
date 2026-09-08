#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e4 + 10;
const int INF = 2147483647;

vector<PII> edges[N];

int n, m, s;

int dist[N];
bool st[N];

void spfa()
{
	for(int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	st[s] = true;
	while(q.size())
	{
		auto t = q.front(); q.pop();
		for(auto e : edges[t])
		{
			int b = e.first, c = e.second;
			//t->b is c;
			if(dist[b] > dist[t] + c)
			{
				dist[b] = dist[t] + c;
				if(!st[b])
				{
					q.push(b);
					st[b] = true;
				}
			}
		}
	}
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

	spfa();
	return 0;
}