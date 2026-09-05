#include<iostream>
#include<vector>
#include<queue>


using namespace std;
const int N = 5e3 + 10;
vector<int> edges[N];
int in[N];
const int MOD = 80112002;

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
	}
	queue<int> q1, q2;
	for(int i = 1; i <= n; i++)
		if(in[i] == 0) q1.push(i);

	int ret = 0;
	while(q1.size() || q2.size())
	{
		if(q1.size() ^ q2.size()) ret = (ret + 1) % MOD;
		if(q1.size())
		{
			int t = q1.front(); q1.pop();
			for(auto e : edges[t])
			{
				in[e]--;
				if(in[e] == 0) q2.push(e);
			}
		}
		if(q2.size())
		{
			int t = q2.front(); q2.pop();
			for(auto e : edges[t])
			{
				in[e]--;
				if(in[e] == 0) q1.push(e);
			}
		}
	}
	cout << ret << endl;
	return 0;	
}