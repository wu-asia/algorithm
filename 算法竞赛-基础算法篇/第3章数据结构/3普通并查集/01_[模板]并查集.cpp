#include<iostream>

using namespace std;

const int N = 2e6 + 10;
int fa[N];
int n, m;

int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
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

int main()
{
	cin >> n >> m;
	//初始化
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	while(m--)
	{
		int z, x, y;
		cin >> z >> x >> y;
		if(z == 1)//合并
		{
			un(x, y);
		}
		else if(z == 2) // 判断
		{
			if(issame(x, y)) cout << "Y" << endl;
			else cout << "N" << endl;
		}
	}
	return 0;
}