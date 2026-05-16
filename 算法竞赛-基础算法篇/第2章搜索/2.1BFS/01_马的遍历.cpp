#include<iostream>
#include<utility>
#include<queue>
#include<cstring>

using namespace std;

const int N = 410;
int a[N][N], f[N][N];
int n, m, x, y;
int dx[] = {1, 2, 1, 2, -2, -1, -1, -2};
int dy[] = {2, 1, -2, -1, 1, 2, -2, -1};
typedef pair<int, int> PII;
void bfs()
{
	memset(f, -1, sizeof f);
	queue<PII> q;
	f[x][y] = 0;
	q.push({x, y});
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		int i = t.first, j = t.second;
		for(int k = 0; k < 8; k++)
		{
			int X = i + dx[k], Y = j + dy[k];
			if(X < 1 || X > n || Y > m || Y < 1)
				continue;
			if(f[X][Y] != -1)
				continue;
			
			f[X][Y] = f[i][j] + 1;
			q.push({X, Y});
		}
	}
}

int main()
{
	cin >> n >> m >> x >> y;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	bfs();

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


// #include<iostream>

// int main()
// {

// 	std::cout << "hell" << std::endl;
// 	return 0;
// }