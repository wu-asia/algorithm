#include<iostream>
#include<cstring>

using namespace std;

const int N = 2e3 + 10;
const int M = 3e3 + 10;
int n, m;
int dist[N];

struct node
{
	int u, v, w;
}a[M * 2];
int pos;

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
			int u = a[j].u, v = a[j].v, w = a[j].w;
			//u->v is w
			if(dist[u] == 0x3f3f3f3f) continue;
			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				flag = true;
			}
		}
		if(flag == false) break;
	}
	if(flag) return true;
	else return false;
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
			a[pos].u = u, a[pos].v = v, a[pos].w = w;
			if(w >= 0)
			{
				pos++;
				a[pos].u = v, a[pos].v = u, a[pos].w = w;
			}
		}
		if(bf()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}