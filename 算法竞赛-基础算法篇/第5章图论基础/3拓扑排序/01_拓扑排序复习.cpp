#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n;
const int N = 110;
int in[N];
vector<int> edges[N];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int j;
		while(cin >> j && j)
		{
			edges[i].push_back(j);
			in[j]++;
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(in[i] == 0)
			q.push(i);
	}
	while(q.size())
	{
		int x = q.front(); q.pop();
		cout << x << " ";
		for(auto e : edges[x])
		{
			in[e]--;
			if(in[e] == 0) q.push(e);
		}
	}
	cout << endl;
	return 0;
}