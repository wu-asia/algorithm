#include<iostream>
#include<cstring>
#include<vector>


using namespace std;

const int N = 1e3 + 10;
const int M = 1e4 + 10;
int n, k, m;
int c[N];
vector<int> edges[M];
bool st[N];
int cnt[N];
void dfs(int u)
{
	st[u] = true;
	cnt[u]++;
	for(auto v : edges[u])
	{
		if(!st[v])
		{
			dfs(v);
		}
	}
}
int main()
{
	cin >> k >> n >> m;
	for(int i = 1; i <= k; i++)
		cin >> c[i];
	for(int i = 1; i <= m; i++)
	{
		int x, y; cin >> x >> y;
		edges[x].push_back(y);
	}

	for(int i = 1; i <= k; i++)
	{
		memset(st, 0, sizeof st);

		dfs(c[i]);
	}

	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		if(cnt[i] == k)
			ret++;
	}
	cout << ret << endl;
	return 0;
}