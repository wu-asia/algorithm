#include<iostream>
#include<cstring>

using namespace std;

const int N = 1010;

int n, m;
int edges[N][N];

int main()
{
	memset(edges, -1, sizeof edges);

	cin >> n >> m;
	//n表示的是顶点的个数，m表示的是边的个数
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		//a - b有一条边，权值为c
		edges[a][b] = c;
		edges[b][a] = c;
	}
	return 0;
}