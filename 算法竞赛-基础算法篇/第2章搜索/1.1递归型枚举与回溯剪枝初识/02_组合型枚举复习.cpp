#include<iostream>
#include<vector>

using namespace std;

vector<int> path;
int n, m;

void dfs(int begin)
{	
	if(path.size() == m)
	{
		for(auto x : path)
		{
			cout << x << " ";
		}
		cout << endl;
		return;
	}

	for(int i = begin; i <= n; i++)
	{
		path.push_back(i);
		dfs(i + 1);
		path.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	dfs(1);
	return 0;
}