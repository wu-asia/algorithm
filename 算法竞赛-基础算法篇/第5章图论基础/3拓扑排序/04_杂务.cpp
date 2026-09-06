#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 1e4 + 10;
int len[N];
vector<int> edges[N];
int f[N];
int in[N], out[N];

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x; cin >> len[x];
		int y;
		while(cin >> y && y)
		{
			edges[y].push_back(x);
			in[x]++; out[y]++;
		}
	}
	for(int i = 1; i <= n; i++)
		f[i] = len[i];

	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(in[i] == 0) q.push(i);
	}
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		for(auto e : edges[t])
		{
			f[e] = max(f[e], len[e] + f[t]);
			in[e]--;
			if(in[e] == 0) q.push(e);
		}
	}
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		if(out[i] == 0)
			ret = max(ret, f[i]);
	}
	cout << ret << endl;
	return 0;
}