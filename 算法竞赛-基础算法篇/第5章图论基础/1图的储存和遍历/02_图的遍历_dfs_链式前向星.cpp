#include<iostream>

using namespace std;
const int N = 1e5 + 10;

//链式前向星
int h[N], e[N * 2], ne[N * 2], w[N * 2], id;
int n, m;

//将b头插到a所在的链表后面
void add(int a, int b, int c)
{
	id++;
	e[id] = b;
	w[id] = c;
	ne[id] = h[a];//多存一个权值信息
	h[a] = id;
}

void dfs(int u)
{
	cout << u << endl;
	st[u] = true;
	for(int i = h[u]; i; i = ne[i])
	{
		int v = e[i];
		if(!st[v])
		{
			dfs(v);
		}
	}
}
int main()
{
	cin >> n >> m;//读入节点个数及变得个数
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	return 0;
}