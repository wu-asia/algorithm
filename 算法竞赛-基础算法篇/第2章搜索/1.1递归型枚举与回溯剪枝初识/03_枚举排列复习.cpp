#include<iostream>
#include<vector>
using namespace std;

int n, k;
const int N = 100;
vector<int> path;
bool st[N];
void dfs()
{
	if(path.size() == k)
	{
		for(auto x : path)
		{
			cout << x << " ";
		}
		cout << endl;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!st[i])
		{
			path.push_back(i);
			st[i] = true;
			dfs();
			path.pop_back();
			st[i] = false;
		}
	}
}
int main()
{
	cin >> n >> k;
	dfs();
	return 0;
}