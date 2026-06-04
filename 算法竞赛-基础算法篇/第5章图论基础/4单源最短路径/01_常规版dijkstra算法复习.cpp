#include<iostream>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;
const int M = 5e5 + 10, INF = 2147483647;
typedef pair<int, int> PII;
const int N = 1e4 + 10;
int n, m, s;
//n表示点的个数
//m表示有向边的个数
//s表示出发点的编号
vector<PII> edges[M];

int dist[N];
bool st[N];

void dijkstra()
{
	for(int i = 0; i <= n; i++)
		dist[i] = INF;
	//选出初始点
	dist[s] = 0;
	for(int i = 1; i <= n; i++)
	{
		int a = 0;
		for(int j = 1; j <= n; i++)
			if(!st[a] && dist[j] < dist[a])
				a = j;

		st[a] = true;
		//松弛操作
		for(auto& e : edges[a])
		{
			int b = e.first, c = e.second;
			//a->b之间有一个权值为c的路径，之前a到b的距离是dist[b]
			//如果dist[a] + c小于
			if(dist[b] + c < dist[a])
				dist[a] = dist[b] + c;
		}
	}

}
int main()
{
	//cout << (int) pow(2, 31) - 1 << endl;
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({v, w});
	}
	dijkstra();
	return 0;
}