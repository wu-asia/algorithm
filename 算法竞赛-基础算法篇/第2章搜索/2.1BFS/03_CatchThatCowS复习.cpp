#include<iostream>
#include<queue>
#include<cstring>
#include<utility>

using namespace std;
int x, y, t;
const int n = 1e5;
const int N = 2e5 + 10;
int dist[N];

void bfs()
{
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	while(q.size())
	{

		int tmp = q.front();
		q.pop();
		int a = tmp + 1, b = tmp - 1, c = tmp * 2;
		if(a <= n && dist[a] == -1)
		{
			q.push(a);
			dist[a] = dist[tmp] + 1;
		}
		if(b >= 0 && dist[b] == -1)
		{
			q.push(b);
			dist[b] = dist[tmp] + 1;
		}
		if(c <= n && dist[c] == -1)
		{
			q.push(c);
			dist[c] = dist[tmp] + 1;
		}
		//剪枝，在有已经到达了y之后，直接跳出循环
		if(a == y || b == y || c == y)
		return;
	}
}
int main()
{
	cin >> t;
	while(t--)
	{
		memset(dist, -1, sizeof dist);
		cin >> x >> y;
		bfs();
		cout << dist[y] << endl;
	}

	return 0;
}