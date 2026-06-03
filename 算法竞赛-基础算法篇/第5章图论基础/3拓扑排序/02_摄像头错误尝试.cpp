#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>

using namespace std;

const int N = 1e4 + 10;

int n;
vector<int> edges[N];
int in[N];
unordered_set<int> mp;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, m, y;
		mp.insert(x);
		cin >> x >> m;
		for(int i = 1; i <= m; i++)
		{
			cin >> y;
			edges[x].push_back(y);
			in[y]++;
		}
	}


	queue<int> q;
	int cnt = 0;
	for(auto& e : mp)
	{
		if(in[e] == 0)
			q.push(e);
	}

	while(q.size())
	{
		auto t = q.front();
		q.pop();
		for(auto& e : edges[t])
		{
			in[e]--;
			if(in[e] == 0 && mp.count(e))
			{
				q.push(e);
			}
		}
	}

	if(cnt == n) cout << "YES" << endl;
	else cout << n - cnt << endl;
	return 0;
}