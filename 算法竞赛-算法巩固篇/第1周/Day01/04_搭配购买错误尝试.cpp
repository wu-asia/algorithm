#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int n, m, w;
//n表示云朵数量，m是搭配书，w为钱的数目
const int N = 1e4 + 10;
int c[N], d[N];
int fa[N];
int cc[N], dd[N];
int f[N];

int find(int x)
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

void un(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	fa[fx] = fy;
}

bool issame(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
	cin >> n >> m >> w;
	for(int i = 1; i <= n; i++)
		cin >> c[i] >> d[i];
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		if(!issame(u, v))
			un(u, v);
	}
	for(int i = 1; i <= n; i++)
	{
		cc[find(i)] += c[i];
		dd[find(i)] += d[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(dd[i] == 0 && cc[i] == 0) continue;
		cnt++;
		c[cnt] = cc[i];
		d[cnt] = dd[i];
	}


		for(int j = w; j >= 1; j--)
		{
			if(j - c[i] >= 0)
				f[j] = max(f[j], f[j - c[i]] + d[i]);
		}

	cout << f[w] << endl;
	return 0;
}