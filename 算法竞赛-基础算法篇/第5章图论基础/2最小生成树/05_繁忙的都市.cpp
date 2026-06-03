//是最小生成树是瓶颈生成树的充分不必要条件
//即是MST->BST
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 8e3 + 10;
const int M = 310;
int n, m;

struct node
{
	int x, y, z;
}a[N];

int cnt, ret;
bool cmp(node& a, node& b)
{
	return a.z < b.z;
}
int fa[M];

int find(int x)
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

void un(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	fa[fx] = fy;
}

bool issame(int x, int y)
{
	return find(x) == find(y);
}

void kruskal()
{
	sort(a + 1, a + m + 1, cmp);
	for(int i = 1; i <= m; i++)
	{
		int x = a[i].x, y = a[i].y, z = a[i].z;
		if(!issame(x, y))
		{
			cnt++;
			un(x, y);
			ret = max(ret, z);
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	kruskal();
	cout << cnt << " " << ret << endl;
	return 0;
}