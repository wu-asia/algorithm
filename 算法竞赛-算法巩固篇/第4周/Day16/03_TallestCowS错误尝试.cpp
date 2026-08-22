#include<iostream>
#include <vector>
#include<cstring>
using namespace std;

const int N = 1e4 + 10;
int n, I, h, r;
const int M = 1e3 + 10;
const int INF = 0x3f3f3f3f;

int pro[N];
vector<int> edges[M];

int main()
{
	cin >> n >> I >> h >> r;
	memset(pro, 0x3f, sizeof pro);

	pro[I] = h;
	for(int i = 1; i <= r; i++)
	{
		int x, y; cin >> x >> y;
		edges[x].push_back(y);
		pro[x] = min(pro[y], pro[x]);
		for(int j = min(x, y) + 1; j < max(x, y); j++)
		{
			pro[j] = min(min(pro[x], pro[y]) - 1, pro[j]);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(auto e : edges[i])
		{
			pro[i] = min(pro[e], pro[i]);
			for(int j = min(i, e) + 1; j < max(i, e); j++)
			{
				pro[j] = min(min(pro[e], pro[i]) - 1, pro[j]);
			}

		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(pro[i] == INF)
			cout << pro[I] << endl;
		else
			cout << pro[i] << endl;
	}
	return 0;
}