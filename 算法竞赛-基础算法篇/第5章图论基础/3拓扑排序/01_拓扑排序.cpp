#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 110;

vector<int> edges[N];
int n;
int in[N]; //记录节点的入度

int main()
{
	cin >> n;
	int x;
	for(int i = 1; i <= n; i++)
	{
		while(cin >> x && x)
		{
			edges[i].push_back(x);
			in[x]++;
		}
	}

	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(in[i] == 0) q.push(i);
	}
	while(q.size())
	{
		int t = q.front();
		cout << t << " ";
		q.pop();
		for(auto& e : edges[t])
		{
			in[e]--;
			if(in[e] == 0)
				q.push(e);
		}
	}
	cout << endl;
	return 0;
}