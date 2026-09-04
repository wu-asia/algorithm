#include<iostream>
#include<utility>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;


typedef long long LL;
typedef pair<int, int> PII;
int n, m;
const int N = 1e5 + 10, M = 2e6 + 10;
int h[N];
vector<PII> edges[N];
bool st[N];
int fa[N];
struct node
{
	int x, y, z;
}e[M];

int find(int x)
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

bool cmp(node& a, node& b)
{
	int y1 = a.y, z1 = a.z, y2 = b.y, z2 = b.z;
	if(y1 != y2) return y1 > y2;
	else return z1 < z2; 
}

LL cnt, pos;

void dfs(int u)
{
	cnt++;
	st[u] = true;
	for(auto p : edges[u])
	{
		int v = p.first, k = p.second;
		pos++;
		e[pos].x = u, e[pos].y = v, e[pos].z = k;
		if(!st[v]) dfs(v);
	}
}

LL kruskal()
{
	LL ret = 0;
	for(int i = 1; i <= pos; i++)
	{
		int x = e[i].x, y = e[i].y, z = e[i].z;
		//cout << "below" << endl;
		//cout << x << " " << y << " " << z << endl;
		if(find(x) == find(y)) continue;
		fa[find(x)] = find(y);
		ret += z;
		//cout << "ret" << ret << endl;
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	for(int i = 1; i <= m; i++)
	{
		int u, v, k;
		cin >> u >> v >> k;
		if(h[u] >= h[v]) edges[u].push_back({v, k});
		if(h[u] <= h[v]) edges[v].push_back({u, k});
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	dfs(1);
	cout << cnt << " ";
	cout << kruskal() << endl;
	return 0;	
}