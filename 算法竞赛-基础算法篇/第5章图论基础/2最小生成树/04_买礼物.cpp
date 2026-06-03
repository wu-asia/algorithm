#include<iostream>
#include<algorithm>

using namespace std;
const int N = 500 * 500  + 10;
const int M = 500;
int a, b;
struct node
{
	int x, y, z;
}e[N];

int fa[M];

int find(int x)
{
	return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
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
int pos;
int cnt, ret;
bool cmp(node& a, node& b)
{
	return a.z < b.z;
}
void kruskal()
{
	sort(e + 1, e + pos + 1, cmp);
	for(int i = 1; i <= pos; i++)
	{
		int x = e[i].x, y = e[i].y, z = e[i].z;
		if(!issame(x, y))
		{
			un(x, y);
			cnt++;
			ret += z;
		}
	}
}

int main()
{

	cin >> a >> b;
	for(int i = 1; i <= b; i++) fa[i] = i;
	for(int i = 1; i <= b; i++)
	{
		for(int j = 1; j <= b; j++)
		{
			int k; cin >> k;
			if(i > j || k == 0 || k > a) continue;
			pos++;
			e[pos].x = i; e[pos].y = j; e[pos].z = k;
		}
	}
	kruskal();
	cout << ret + (b - cnt) * a << endl;
	return 0;
}