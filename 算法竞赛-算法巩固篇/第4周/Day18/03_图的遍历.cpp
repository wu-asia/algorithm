#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int M = 1e5 + 10;
const int N = 1e5 + 10;
int n, m;
vector<int> edges[M];

int a[N];
bool st[N];

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	st[x] = true;
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		edges[x].push_back(y);
	}
	for(int i = 1; i <= n; i++)
		a[i] = i;
	for(int i = 1; i <= n; i++)
		bfs(i);
	return 0;
}