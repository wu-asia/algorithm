#include<iostream>
#include<vector>

using namespace std;
const int N = 20;
int n, k;
vector<int> path;
bool st[N];
void dfs()
{

	if(path.size() == k)
	{
		for(auto x : path)
			cout << x << " ";
		cout << endl;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(st[i]) continue;
		path.push_back(i);
		st[i] = true;
		dfs();
		//回溯 + 回复现场
		path.pop_back();
		st[i] = false;
	}
	

}
int main()
{
	cin >> n >> k;
	dfs();
	return 0;
}