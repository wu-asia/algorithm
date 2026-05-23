#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;
const int N = 100;
vector<int> path;
int n;
bool st[N];
void dfs()
{
	if(path.size() == n)
	{
		for(auto x : path)
		{
			cout << setw(5) << x;
		}
		cout << endl;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(st[i]) continue;
		path.push_back(i);
		st[i] = true;
		dfs();
		path.pop_back();
		st[i] = false;
	}
}
int main()
{
	cin >> n;
	dfs();
	return 0;
}