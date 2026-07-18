#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int n, m, x, y;
const int N = 410;
int f[N][N];
int st[N][N];
int dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[] = {2, 1, -2, -1, -2, -1, 2, 1};

struct node
{
	int x, y;
};

int main()
{
	cin >> n >> m >> x >> y;
	memset(f, -1, sizeof f);
	st[x][y] = true;
	queue<node> q;
	f[x][y] = 0;
	q.push({x, y});
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		for(int i = 0; i < 8; i++)
		{
			int a = t.x + dx[i], b = t.y + dy[i];
			if(a < 1 || a > n || b < 1 || b > m || st[a][b])
				continue;
			f[a][b] = f[t.x][t.y] + 1;
			q.push({a, b});
			st[a][b] = true;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}