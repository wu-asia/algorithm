#include<iostream>
#include<string>

using namespace std;

int n, ret;
const int N = 30;
int cnt[N];
string a[N];

void dfs(string path)
{
	if(path.size() > ret) ret = path.size();
	for(int i = 1; i <= n; i++)
	{
		if(cnt[i] >= 2) continue;
		int cur1 = path.size() - 1;
		int cur2 = 0;
		while(cur1 > 0 && cur2 < a[i].size() - 1)
		{
			if(path.substr(cur1) == a[i].substr(0, cur2 + 1))
			{
				cnt[i]++;
				dfs(path + a[i].substr(cur2 + 1));
				cnt[i]--;
			}
			cur1--;cur2++;
		}
	}
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	char ch;
	cin >> ch;
	for(int i = 1; i <= n; i++)
	{
		if(cnt[i] >= 2) continue;
		if(a[i][0] == ch)
		{
			cnt[i]++;
			dfs(a[i]);
			cnt[i]--;
		}
	}
	cout << ret << endl;
	return 0;
}