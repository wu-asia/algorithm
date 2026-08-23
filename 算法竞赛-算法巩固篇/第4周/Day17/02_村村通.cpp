#include<iostream>
#include<cstring>


using namespace std;

const int N = 1e3 + 10;
int fa[N];

int find(int x)
{
	return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
}

void unionate(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	fa[fx] = fy;
}

bool issame(int x, int y)
{
	return find(x) == find(y);
}

bool st[N];
int main()
{
	int n, m;
	while(cin >> n && n && cin >> m)
	{
		memset(st, 0, sizeof st);
		for(int i = 1; i <= n; i++) fa[i] = i;
		for(int i = 1; i <= m; i++)
		{
			int x, y; cin >> x >> y;
			unionate(x, y);
		}
		for(int i = 1; i <= n; i++)
		{
			//cout << find(i) << " ";
			st[find(i)] = true;
		}
		//cout << endl;
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(st[i])
			{
				//cout << i << " ";
				cnt++;
			}
		}
		cout << cnt - 1 << endl;
	}
	//cout << "true" << endl;
	return 0;
}