#include<iostream>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;
const int N = 5010, INF = 0x3f3f3f3f;

typedef pair<int, int> PII;
int dist[N];
bool st[N];

vector<PII> edges[N];
int n, m;

int prim()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		int t = 0;
		for(int j = 1; j <= n; j++)
			if(!st[j] && dist[j] < dist[t])
				t = j;
		//判断是否是连通图
		if(dist[t] == INF) return INF;
		st[t] = true;
		ret += dist[t];
		for(auto& e : edges[t])
		{
			int a = e.first, b = e.second;
			//a和t之间有一条边，权值为b
			dist[a] = min(dist[a], b);
		}
	}
	return ret;
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edges[x].push_back({y, z});
		edges[y].push_back({x, z});
	}

	int ret = prim();
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	return 0;
}


