#include<iostream>

#include<algorithm>

using namespace std;

int pos;
int cnt, ret;
int a, b;

const int N = 5010;
struct node
{
	int x, y, z;
}edges[N];

bool cmp(node& a, node& b)
{
	return a.z < b.z;
}

int find(int x)
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

void unionate(int x, int y)
{
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
}

int kruskal()
{
	for(int i = 1; i <= pos; i++)
	{
		int x = edges[i].x, y = edges[i].y, z = edges[i].z;
		if(find(x) == find(y)) continue;
		ret += z;
		cnt++;
		unionate(x, y);
	}
}
int main()
{
	cin >> a >> b;
	for(int i = 1; i <= b; i++)
	{
		for(int j = 1; j <= b; j++)
		{
			int z;
			cin >> z;
			if(i >= j || k == 0) continue;

			pos++;
			edges[pos].x = i, edges[pos].y = j, edges[pos].z = z;
		}
	}
	for(int i = 1; i <= pos; i++) fa[i] = i;

	sort(edges + 1, edges + 1 + pos, cmp);

	kruskal();
	cout << ret + (b - cnt) * a << endl;
	return 0;
}