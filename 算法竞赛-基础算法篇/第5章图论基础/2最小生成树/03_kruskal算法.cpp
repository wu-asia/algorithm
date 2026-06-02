//kruskal算法时间复杂度:O(mlogm)
//m表示的是图的边的个数
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 5010, M = 2e5 + 10; 
const int INF = 0x3f3f3f3f;

struct node
{
	int x, y, z;
}a[M];

int n, m;
int fa[N];

int find(int x)
{
	return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}

bool cmp(node& a, node& b)
{
	return a.z < b.z;
}

int kruskal()
{
	sort(a + 1, a + m + 1, cmp);
	int cnt = 0;
	int ret = 0;
	//遍历所有的边
	for(int i = 1; i <= m; i++)
	{
		int x = a[i].x, y = a[i].y, z = a[i].z;
		//判断两个节点是否相连接
		if(find(x) != find(y))
		{
			cnt++;
			ret += z;
			//合并
			fa[find(x)] = find(y);
		}

	}
	return cnt == n - 1 ? ret : INF;
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	for(int i = 1; i <= n; i++) fa[i] = i;
	int ret = kruskal();
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	return 0;
}