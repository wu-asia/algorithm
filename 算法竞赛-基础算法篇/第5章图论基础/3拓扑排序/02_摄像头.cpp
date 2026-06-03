#include<iostream>
#include<queue>
#include<vector>

using namespace std;
const int N = 5010;
int n;
vector<int> edges[N];
bool st[N];
int in[N];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, m, y;
		
		cin >> x >> m;
		st[x] = true;
		for(int i = 1; i <= m; i++)
		{
			cin >> y;
			edges[x].push_back(y);
			in[y]++;
		}
	}

	queue<int> q;
	for(int i = 1; i <= 500; i++)
		if(st[i] && in[i] == 0)
			q.push(i);

	while(q.size())
	{
		auto t = q.front();
		q.pop();
		for(auto& e : edges[t])
		{
			in[e]--;
			if(st[e] && in[e] == 0)
				q.push(e);
		}
	}
	int ret = 0;
	for(int i = 1; i <= 500; i++)
		if(st[i] && in[i])
			ret++;
	if(!ret) cout << "YES" << endl;
	else cout << ret << endl;
	return 0;
}