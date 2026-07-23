#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

typedef long long LL;
LL t;
const int N = 1e3 + 10;
LL n, h, r;
LL x[N], y[N], z[N];

vector<int> edges[N];

bool check(int i, int j)
{
	LL x1 = x[i], y1 = y[i], z1 = z[i];
	LL x2 = x[j], y2 = y[j], z2 = z[j];
	LL dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
	if(dist <= 4 * r * r) return true;
	return false;
}
bool st[N];

bool dfs(int x)
{
	if(x == n + 1) return true;
	st[x] = true;
	for(auto e : edges[x])
	{
		if(st[e] == true) continue;
		if(dfs(e)) return true;
	}
	return false;
}
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> h >> r;
		for(int i = 1; i <= n; i++)
			cin >> x[i] >> y[i] >> z[i];
		for(int i = 0; i <= n + 1; i++)
			edges[i].clear();
		for(int i = 1; i <= n; i++)
			if(z[i] <= r)
			{
				edges[0].push_back(i);
				edges[i].push_back(0);
			}
		for(int i = 1; i <= n; i++)
			if(z[i] + r >= h)
			{
				edges[n + 1].push_back(i);
				edges[i].push_back(n + 1);
			}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i == j) continue;
				if(check(i, j))
				{
					edges[i].push_back(j);
					edges[j].push_back(i);
				}
			}
		}
		memset(st, 0, sizeof st);
		bool flag = false;
		for(auto e : edges[0])
		{
			if(dfs(e)) flag = true;
		}
		if(flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}