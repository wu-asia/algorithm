#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5010, M = 2e5 + 10, INF = 0x3f3f3f3f;

int n, m;

struct node
{
	int x, y, z;
}a[M];

bool cmp(node& a, node&b)
{
	return a.z < b.z;
}

int fa[N];

int find(int x)
{
	return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}

void un(int x, int y)
{
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
}

bool issame(int x, int y)
{
	return find(x) == find(y);
}

int kruskal()
{
	sort(a + 1, a + 1 + m, cmp);
	int ret = 0;
	int cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		int x = a[i].x, y = a[i].y, z = a[i].z;
		if(!issame(x, y))
		{
			cnt++;
			ret += z;
			un(x, y);
		}
	}
	return cnt == n - 1 ? ret : INF;
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	//初始化并查集
	for(int i = 1; i <= n; i++) fa[i] = i;
	int ret = kruskal();

	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	return 0;
}