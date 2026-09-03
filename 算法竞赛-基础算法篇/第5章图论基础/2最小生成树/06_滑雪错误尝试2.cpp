#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int n, m;
vector<PII> edges[N];
int dist[N];
bool st[N];
int h[N];

long long ret, cnt;
void prim()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 1; i <= n; i++)
	{
		int t = 0;
		for(int j = 1; j <= n; j++)
			if(!st[j] && dist[j] < dist[t])
				t = j;
		if(dist[t] == INF) return;
		st[t] = true;
		ret += dist[t];
		cnt++;
		for(auto e : edges[t])
		{
			// t -> v is k
			int v = e.first, k = e.second;
			dist[v] = min(dist[v], k);
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	for(int i = 1; i <= m; i++)
	{
		int u, v, k; cin >> u >> v >> k;
		if(h[u] < h[v]) swap(u, v);
		edges[u].push_back({v, k});
	}
	prim();
	cout << cnt << " " << ret << endl;
	return 0;
}