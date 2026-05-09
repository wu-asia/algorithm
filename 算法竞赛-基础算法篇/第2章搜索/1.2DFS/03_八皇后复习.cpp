#include<iostream>
#include<vector>

using namespace std;

int n;
const int N = 20;
bool col[N], st1[N * 2], st2[N * 2];
vector<int> path;
int ret;
void dfs(int x)
{
	if(x > n)
	{
		ret++;
		if(ret <= 3)
		{
			for(auto x : path)
			{
				cout << x << " ";
			}
			cout << endl;
			return;
		}
	}
	for(int y = 1; y <= n; y++)
	{
		if(col[y] || st1[y - x + n] || st2[y + x])
			continue;
		col[y] = st1[y - x + n] = st2[y + x] = true;
		path.push_back(y);
		dfs(x + 1);
		col[y] = st1[y - x + n] = st2[y + x] = false;
		path.pop_back();
	}
}
int main()
{
	cin >> n;
	dfs(1);
	cout << ret << endl;
	return 0;
}