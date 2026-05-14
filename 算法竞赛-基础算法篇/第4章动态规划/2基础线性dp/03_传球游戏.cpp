#include<iostream>
#include<cstring>
#include<queue>
#include<utility>

using namespace std;
int n, m, x, y;
const int N = 40;
int dist[N][N];
typedef pair<int, int> PII;
void bfs()
{
	queue<PII> q;
	q.push({x, y});
	dist[x][y] = 0;
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		int X = t.first, Y = t.second;
		if(X < 1 || X > n || Y < 1 || Y > m)
			continue;
		if(dist[X][Y] == -1) continue;
		q.push({X, Y});
		dist[X][Y] = dist[i][j] + 1;
	}
}
int main()
{
	cin >> n >> m >> x >> y;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> dist[i][j];
	memset(dist, -1, sizeof dist);

	bfs();
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}