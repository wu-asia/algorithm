#include<iostream>

using namespace std;
const int N = 1e4 + 10;
int n, m, p;
int fa[N];
int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
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
int main()
{
	cin >> n >> m >> p;
	//初始化指向自身
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	while(m--)
	{
		int x, y;
		cin >> x >> y;
		un(x, y);
	}
	while(p--)
	{
		int x, y;
		cin >> x >> y;
		if(issame(x, y))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}