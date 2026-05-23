#include<iostream>
#include<vector>

using namespace std;

const int N = 15;
int n;

int ret;
vector<int> path;
bool col[N * 2], st1[N * 2], st2[N * 2];
void dfs(int x)//参数是列
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
		}
		return;
	}

	for(int y = 1; y <= n; y++)
	{
		//剪枝
		if(col[y] || st1[y - x + n] || st2[x + y]) continue;
		col[y] = st1[y - x + n] = st2[x + y] = true;
		path.push_back(y);
		dfs(x + 1);
		col[y] = st1[y - x + n] = st2[x + y] = false;
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