#include<iostream>
#include<queue>

using namespace std;

const int N = 40;
int n, m;
char ch[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool st[N][N];
int f[N][N];

struct node
{
	int x, y;
};

int ret = 0x3f3f3f3f;
int cnt = 0;
void bfs(int x, int y)
{
	st[x][y] = true;
	queue<node> q;
	q.push({x, y});
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int a = t.x + dx[i], b = t.y + dy[i];
			if(st[a][b] || a < 0 || a >= n ||
			 b < 0 || b >= m || ch[a][b] == '*' )
				continue;
			f[a][b] = f[t.x][t.y] + 1;
			st[a][b] = true;
			if(ch[a][b] == 'e')
			{
				ret = min(ret, f[a][b]);
				cnt++;
			}
			else
				q.push({a, b});
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> ch[i];
	int x, y;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			if(ch[i][j] == 'k')
				x = i, y = j;
	}
	//cout << x << " " << y << endl;
	bfs(x, y);
	// for(int i = 0; i < n; i++)
	// {
	// 	for(int j = 0; j < m; j++)
	// 		cout << f[i][j] << " ";
	// 	cout << endl;
	// }
	if(cnt == 0)
		cout << -1 << endl;
	else
		cout << cnt << " " << ret << endl;
	return 0;
}