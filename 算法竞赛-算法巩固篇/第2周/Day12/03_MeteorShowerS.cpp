#include<iostream>
#include<queue>
#include<utility>
#include<cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 310;
const int INF = 0x3f3f3f3f;

int tim[N][N];
bool st[N][N];

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int dist[N][N];

int bfs()
{
	if(tim[0][0] == INF) return 0;
	memset(dist, 0x3f, sizeof dist);
	queue<PII> q;
	q.push({0, 0});
	dist[0][0] = 0;
	while(q.size())
	{
		auto a = q.front();
		q.pop();
		int x = a.first, y = a.second;
		for(int k = 0; k < 4; k++)
		{
			int i = x + dx[k], j = y + dy[k];
			if(i < 0 || j < 0) continue;
			if(dist[x][y] + 1 >= tim[i][j]) continue;
			if(dist[i][j] != INF) continue; //之前已经走过了

			dist[i][j] = dist[x][y] + 1;

			if(tim[i][j] == INF) return dist[i][j];
			q.push({i, j});
		}
	}
	return -1;
}
int main()
{
	int m;
	cin >> m;
	memset(tim, 0x3f, sizeof tim);
	for(int i = 1; i <= m; i++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		tim[x][y] = min(tim[x][y], t);
		for(int k = 0; k < 4; k++)
		{
			int i = x + dx[k], j = y + dy[k];
			if(i < 0 || j < 0) continue;
			tim[i][j] = min(tim[i][j], t);
		}
	}

	cout << bfs() << endl;

	return 0;
}