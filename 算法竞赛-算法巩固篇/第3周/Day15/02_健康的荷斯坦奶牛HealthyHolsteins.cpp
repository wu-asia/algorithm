#include<iostream>

using namespace std;

const int N = 30;
int n, m;
int v[N];
int g[N][N];

int path;
int cnt;
int ret = N;
int p;
bool check()
{
	for(int i = 1; i <= n; i++)
	{
		int sum = 0;
		for(int j = 1; j <= m; j++)
		{
			if((path >> j) & 1)
			{
				sum += g[j][i];
			}
		}
		if(sum < v[i])
			return false;
	}
	return true;
}

void dfs(int pos)
{
	if(cnt >= ret) return;
	if(check())
	{
		ret = cnt;
		p = path;
		return;
	}
	if(pos > m) return;
	// 选
	cnt++;
	path = (1 << pos) | path;
	dfs(pos + 1);
	cnt--;
	path = ~(1 << pos) & path;
	
	// 不选
	dfs(pos + 1);

}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	cin >> m;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			cin >> g[i][j];

	dfs(1);
	cout << ret << " ";
	for(int i = 1; i <= n; i++)
	{
		if((p >> i) & 1)
		{
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}