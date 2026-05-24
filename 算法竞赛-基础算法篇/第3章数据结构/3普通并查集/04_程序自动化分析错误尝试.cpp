//仅仅是因为没有使用离散化，没有全部AC
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;
int t;
int fa[N];

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void un(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	fa[fy] = fx;
}

bool issame(int x, int y)
{
	return (find(x) == find(y));
}

struct node
{
	int i, j;
};

vector<node> a;
int main()
{
	cin >> t;
	while(t--)
	{
		int n = 0;
		cin >> n;
		for(int i = 1; i < 2 * n; i++)
			fa[i] = i;
		a.clear();
		while(n--)
		{
			int i, j, e;
			cin >> i >> j >> e;
			if(e == 1)
			{
				un(max(i, j), min(i, j));
			}
			else if(e == 0)
			{
				a.push_back({i, j});
			}
		}
		bool flag = true;
		for(auto x : a)
		{
			int k = x.i;
			int l = x.j;
			if(issame(k, l))
			{
				cout << "NO" << endl;
				flag = false;
			}
		}
		if(flag) cout << "YES" << endl;
	}
	return 0;
}