#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 510;
vector<int> edges[N];
int n;
int in[N];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, m, y;
		cin >> x >> m;
		for(int j = 1; j <= m; j++)
		{
			cin >> y;
			if(y > n) continue;
			edges[x].push_back(y);
			in[y]++;
		}
	}

	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(in[i] == 0) q.push(i);
	}
	int cnt = 0;
	// cout << endl;
	// for(int i = 1; i <= n; i++)
	// 	cout << in[i] << " ";
	// cout << endl;
	while(q.size())
	{
		int t = q.front();
		cnt++;
		q.pop();
		
		for(auto e : edges[t])
		{
			in[e]--;
			if(in[e] == 0) q.push(e);
		}
	}
	if(n - cnt == 0) cout << "YES" << endl;
	else cout << n - cnt << endl;
	return 0;
}