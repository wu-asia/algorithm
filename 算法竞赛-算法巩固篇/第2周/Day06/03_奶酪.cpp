#include<iostream>

using namespace std;

typedef long long LL;

LL t;
LL n, h, r;
const int N = 1e3 + 10;
LL x[N], y[N], z[N];
LL fa[N];

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
	fa[find(x)] = find(y);
}

bool check(int i, int j)
{
	LL x1 = x[i], y1 = y[i], z1 = z[i];
	LL x2 = x[j], y2 = y[j], z2 = z[j];
	LL dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
	if(dist <= 4 * r * r) return true;
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
			fa[i] = i;
		for(int i = 1; i <= n; i++)
		{
			if(z[i] <= r) merge(0, i);
			if(z[i] + r >= h) merge(n + 1, i);
			for(int j = 1; j <= n; j++)
			{
				if(check(i, j)) merge(i, j);
			}
		}
		if(find(0) == find(n + 1)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}