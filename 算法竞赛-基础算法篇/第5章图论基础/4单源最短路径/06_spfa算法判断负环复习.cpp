#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<cstring>

using namespace std;
const int N = 2e3 + 10;
int n, m;
typedef pair<int, int> PII;
vector<PII> edges[N];
int dist[N];
bool st[N];
int cnt[N];

bool spfa()
{
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);
	queue<int> q;
	dist[1] = 0;
	q.push(1);
	st[1] = true;
	while(q.size())
	{
		int u = q.front();
		q.pop();
		st[u] = false;
		for(auto& e : edges[u])
		{
			int v = e.first, w = e.second;
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				cnt[v] = cnt[u] + 1;
				if(cnt[v] >= n) return true;
				if(!st[v])
				{
					q.push(v);
					st[v] = true;
				}
			}

		}
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			edges[i].clear();
		for(int i = 1; i <= m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			edges[u].push_back({v, w});
			if(w >= 0)
				edges[v].push_back({u, w});
		}
		if(spfa()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}