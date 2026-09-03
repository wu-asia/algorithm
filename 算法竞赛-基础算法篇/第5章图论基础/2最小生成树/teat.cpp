#include<iostream>
#include<algorithm>

using namespace std;
int n, m;
const int M = 8010;
const int N = 310;
struct node
{
	int u, v, c;
}a[M];
int fa[N];

bool cmp(node& x, node& y)
{
	return x.c < y.c;
}

int find(int x)
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

int mm = 0;
int kruskal()
{
	int ret = 0, cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		int u = a[i].u, v = a[i].v, c = a[i].c;
		if(find(u) == find(v)) continue;
		ret += c;
		fa[find(u)] = find(v);
		cnt++;
		mm = max(mm, c);
	}
	return cnt;
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		a[i].u = u, a[i].v = v, a[i].c = c;
	}
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	sort(a + 1, a + 1 + m, cmp);
	int ret = kruskal();
	cout << ret << " " << mm << endl;
	return 0;
}