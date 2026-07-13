#include<iostream>
#include<vector>

using namespace std;

int n, m, w;
const int N = 1e4 + 10;
int c[N], d[N];
int cc[N], dd[N];
int cnt = 0;
int f[N];
bool st[N];
vector<int> edges[N];
void dfs(int a)
{
	st[a] = true;
	dd[cnt] += d[a];
	cc[cnt] += c[a];
	for(auto& b : edges[a])
	{
		if(!st[b]) dfs(b);
	}
}

int main()
{
	cin >> n >> m >> w;
	for(int i = 1; i <= n; i++)
		cin >> c[i] >> d[i];
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!st[i])
		{
			cnt++;
			dfs(i);
		}
	}
	for(int i = 1; i <= cnt; i++)
	{
		for(int j = w; j >= 1; j--)
			if(j - cc[i] >= 0)
				f[j] = max(f[j], f[j - cc[i]] + dd[i]);
	}
	cout << f[w] << endl;
	return 0;
}