#include<iostream>
#include<cstring>

using namespace std;

const int N = 15;
int T, n;
int t[N], d[N], l[N];
bool st[N];
bool dfs(int pos, int end)
{
	if(pos > n)
		return true;
	for(int i = 1; i <= n; i++)
	{
		//剪枝
		if(st[i] == true) continue;
		if(t[i] + d[i] < end) continue;
		st[i] = true;
		int new_end = max(end, t[i]) + l[i];
		//dfs(pos + 1, new_end);
		if(dfs(pos + 1, new_end)) return true;
		//回溯
		st[i] = false;
	}

	return false;
}
int main()
{
	cin >> T;
	while(T--)
	{
		memset(st, 0, sizeof st);
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> t[i] >> d[i] >> l[i];
		if(dfs(1, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}