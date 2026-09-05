#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 5e3 + 10;
const int MOD = 80112002;

vector<int> edges[N];
int in[N], out[N];
int f[N];
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		edges[x].push_back(y);
		in[y]++;
		out[x]++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(in[i] == 0)
		{
			q.push(i);
			f[i] = 1;
		}
	}
	
	while(q.size())
	{
		int t = q.front();
		q.pop();
		for(auto e : edges[t])
		{
			f[e] = (f[e] + f[t]) % MOD;
			in[e]--;
			if(in[e] == 0) q.push(e);
		}
	}
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		if(out[i] == 0)
			ret = (ret + f[i]) % MOD;
	}
	cout << ret << endl;
	return 0;
}