#include<iostream>
#include<queue>

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

bool st[N];

void bfs(int u)
{
	queue<int> q;
	q.push(u);
	st[u] = true;
	while(q.size())
	{
		auto a = q.front(); 
		q.pop();
		cout << a << endl;
		for(int i = h[i]; i; i = ne[i])
		{
			int b = e[i], c = w[i];
			if(!st[b])
			{
				q.push(b);
				st[b] = true;
			}
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