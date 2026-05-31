#include<iostream>
#include<vector>
#include<utility>

using namespace std;

typedef pair<int, int> PII;
//first表示与那个顶点相连，second表示的是这条边的权值
const int N = 1e5 + 10;

int n, m;
vector<PII> edges[N];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		//a和b之间有一条边，权值为c
		edges[a].push_back({b, c});
		//如果是无向边，需要反过来在存一下
		edges[b].push_back({a, c});
	}
	return 0;
}