#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5010, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m;
struct node
{
	int x, y, z;
}a[M];

int fa[N];

int find(int x)
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

bool cmp(node& a, node& b)
{
	return a.z < b.z;
}
int kruskal()
{
	int cnt = 0, ret = 0;
	sort(a + 1, a + 1 + m, cmp);
	for(int i = 1; i <= m; i++)
	{
		int x = a[i].x, y = a[i].y, z = a[i].z;
		int fx = find(x);
		int fy = find(y);
		if(fx != fy)
		{
			fa[fx] = fy;
			cnt++;
			ret += z;
		}
	}
	return cnt == n - 1 ? ret : INF;
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= m; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	int ret = kruskal();
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	return 0;
}