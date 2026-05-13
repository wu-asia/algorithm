#include<algorithm>
#include<iostream>
using namespace std;

int m, n;
const int N = 110;
int a[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int f[N][N];
int dfs(int i, int j)
{
	if(f[i][j]) return f[i][j];
	int len = 1;
	for(int k = 0; k < 4; k++)
	{
		int x = i + dx[k], y = j + dy[k];
		if(x < 0 || x >= n || y < 0 || y >= m)
			continue;
		if(a[x][y] >= a[i][j])
			continue;
		len = max(dfs(x, y) + 1, len);
	}
	return f[i][j] = len;

}
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];

	int ret = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ret = max(ret, dfs(i, j));
	cout << ret << endl;
	return 0;
}