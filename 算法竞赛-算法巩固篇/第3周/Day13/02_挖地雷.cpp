#include<iostream>

using namespace std;

const int N = 30;

int n;
int cnt[N];
int f[N];
int edge[N][N];
int pre[N];

void dfs(int x)
{
	if(pre[x]) dfs(pre[x]);
	cout << x << " ";
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> cnt[i];
	for(int i = 1; i < n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			cin >> edge[i][j];
		}
	}
	for(int i = 1; i <= n; i++)
		f[i] = cnt[i];

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < i; j++)
		{
			if(edge[j][i])
			{
				if(f[i] < f[j] + cnt[i])
				{
					f[i] = f[j] + cnt[i];
					pre[i] = j;
				}
			}
		}
	}

	int ret = 0, p = 0;
	for(int i = 1; i <= n; i++)
	{
		if(f[i] > ret)
		{
			ret = f[i];
			p = i;
		}
	}
	dfs(p);
	cout << endl << ret << endl;
	return 0;
}