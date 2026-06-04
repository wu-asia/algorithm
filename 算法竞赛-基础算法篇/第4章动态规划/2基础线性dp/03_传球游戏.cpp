#include<iostream>
<<<<<<< HEAD
using namespace std;

const int N = 50;
typedef long long LL;
LL n, m;
LL f[N][N]; //f[i][j]表示第i次传球，传到第j个人手中的方案数
int main()
{
	cin >> n >> m;
	f[0][1] = 1;
	for(int i = 1; i <= m; i++)
	{
		f[i][1] = f[i - 1][2] + f[i - 1][n];
		for(int j = 2; j < n; j++)
			f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
		f[i][n] = f[i - 1][n - 1] + f[i - 1][1];
	}
	cout << f[m][1] << endl;

=======
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
>>>>>>> 7295335930111d37c7acca8b6884e789d2511697
	return 0;
}