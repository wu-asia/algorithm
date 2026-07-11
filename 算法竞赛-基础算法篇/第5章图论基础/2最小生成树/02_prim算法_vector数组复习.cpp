#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 5010, INF = 0x3f3f3f3f;

struct node
{
	int y, z;
};
vector<node> edges[N];
int n, m;
int dist[N];
bool st[N];

int prim()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		int t = 0;
		for(int j = 1; j <= n; j++)
		{
			if(!st[j] && dist[j] < dist[t])
				t = j;
		}

		if(dist[t] == INF) return INF;
		st[t] = true;
		ret += dist[t];
		for(auto e : edges[t])
		{
			int y = e.y, z = e.z;
			//t->y的距离是z
			dist[y] = min(dist[y], e.z);
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