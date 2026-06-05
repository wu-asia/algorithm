#include<iostream>
#include<cstring>

using namespace std;

const int N = 3e3 + 10;
int pos;
const int INF = 0x3f3f3f3f;

struct node
{
	int u, v, w;
}e[N * 2];
int n, m;
int dist[N];
bool bf()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	bool flag;
	for(int i = 1; i <= n; i++)
	{
		flag = false;
		for(int j = 1; j <= pos; j++)
		{
			int u = e[j].u, v = e[j].v, w = e[j].w;
			if(dist[u] != INF && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				flag = true;
			}
		}
		if(flag == false) return flag;
	}
	
	return flag;
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		pos = 0;
		for(int i = 1; i <= m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			pos++;
			e[pos].u = u; e[pos].v = v; e[pos].w = w;
			if(w >= 0)
			{
				pos++;
				e[pos].u = v; e[pos].v = u; e[pos].w = w;
			}
		}
		if(bf()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}