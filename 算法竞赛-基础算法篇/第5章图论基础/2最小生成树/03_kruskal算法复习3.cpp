#include<iostream>
#include<algorithm>

using namespace std;
const int N = 5010;
const int M = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int n, m;
struct node
{
	int x, y, z;
}edges[M];


bool cmp(node& a, node& b)
{
	return a.z < b.z;
}
int fa[N];

int find(int x)
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

void unionate(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	fa[fx] = fy;
}

bool issame(int x, int y)
{
	return find(x) == find(y);
}

int kruskal()
{
	int ret = 0, cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		int x = edges[i].x, y = edges[i].y, z = edges[i].z;
		if(issame(x, y)) continue;
		unionate(x, y);
		ret += z;
		cnt++;
	}
	if(cnt != n - 1) return INF;
	else return ret;
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> edges[i].x >> edges[i].y >> edges[i].z;
	sort(edges + 1, edges + 1 + m, cmp);
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	int ret = kruskal();
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	return 0;
}