#include<iostream>
#include<vector>

using namespace std;

const int N = 15;
bool row[N], col[N];
int n;
int ret, cnt;
vector<int> path;
void dfs(int pos)
{
	if(pos > n / 2)
	{
		ret++;
		if(ret <= 3)
		{
			for(auto x : path)
			{
				cout << x << " ";
			}
			cout << endl;
		}
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(row[i] == true && col[j] == true) continue;
			row[i] = true;
			col[j] = true;
			path.push_back(j);
			dfs(pos + 1);
			path.pop_back();
			row[i] = false;
			col[j] = false;
		}
	}
}
int main()
{
	cin >> n;
	dfs(1);
	cout << ret << endl;
	return 0;
}