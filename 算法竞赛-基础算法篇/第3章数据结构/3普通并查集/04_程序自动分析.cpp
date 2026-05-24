#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;
const int N = 1e5 + 10;
struct node
{
	int x, y, e;
};
int t;
node a[N];
int pos;
int disc[N * 2];
unordered_map<int, int> id;
int fa[N * 2];
int n;
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void un(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	fa[fx] = fy;
}

bool issame(int x, int y)
{
	return (find(x) == find(y));
}
bool solve()
{
	pos = 0;
	id.clear();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].e;
		disc[++pos] = a[i].x;
		disc[++pos] = a[i].y;
	}
	//离散化
	sort(disc + 1, disc + 1 + pos);
	int cnt = 0;
	for(int i = 1; i <= pos; i++)
	{
		int tmp = disc[i];
		if(id.count(tmp)) continue;
		cnt++;
		id[tmp] = cnt;
	}

	for(int i = 1; i <= cnt; i++)
		fa[i] = i;

	for(int i = 1; i <= n; i++)
	{
		int x = a[i].x, y = a[i].y, e = a[i].e;
		if(e == 1)
		{
			un(id[x], id[y]);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int x = a[i].x, y = a[i].y, e = a[i].e;
		if(e == 0)
		{
			if(issame(id[x], id[y]))
				return false;
		}
	}

	return true;
}
int main()
{
	cin >> t;
	while(t--)
	{
		if(solve()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}