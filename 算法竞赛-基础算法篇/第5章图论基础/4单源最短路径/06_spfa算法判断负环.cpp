#include<iostream>
#include<utility>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;
const int N = 6e3 + 10;
int n, m;
typedef pair<int, int> PII;
vector<PII> edges[N];
int dist[N], cnt[N];
bool st[N];

bool spfa()
{
	memset(dist, 0x3f, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	memset(st, 0, sizeof st);
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	st[1] = true;
	while(q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		for(auto& e : edges[t])
		{
			int v = e.first, w = e.second;
			if(dist[t] != 0x3f3f3f3f && dist[t] + w < dist[v])
			{
				dist[v] = dist[t] + w;
				if(!st[v])
				{
					q.push(v);
					st[v] = true;
				}
				cnt[v] = cnt[t] + 1;
				if(cnt[v] > n - 1) return true;
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