//prim的时间复杂度:O(n^2)
//n表示的是图的节点个数
#include<iostream>
#include<cstring>

using namespace std;

const int N = 5010, INF = 0x3f3f3f3f;

int n, m;
int edges[N][N]; //邻接矩阵存储图

int dist[N]; //某个带你距离生成树的最短距离
bool st[N];//标记哪些点已经计入到生成树

int prim()
{
	//初始化
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	int ret = 0;

	for(int i = 1; i <= n; i++) //循环加入n个点
	{
		//1.找到最近点
		int t = 0;
		for(int j = 1; j <= n; j++)
			if(!st[j] && dist[j] < dist[t])
				t = j;
		//判断是否连通
		if(dist[t] == INF) return INF;
		st[t] = true;
		ret += dist[t];
		//2.更新距离
		for(int j = 1; j <= n; j++) //枚举t走到哪里
			dist[j] = min(dist[j], edges[t][j]);
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	//初始化 邻接矩阵
	memset(edges, 0x3f, sizeof edges);
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edges[x][y] = edges[y][x] = min(edges[x][y], z);
	}

	int ret = prim();
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	return 0;
}