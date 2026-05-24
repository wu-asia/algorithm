//代码的逻辑无漏洞
//只是使用的是暴力搜索，会超出时间限制
//无法是代码AC

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 400;
const int M = 150;
//a[i]表示棋盘第i个格子中的分数
//b[i]表示第i张卡片上的数字
int a[N], b[M];
int n, m;
long long path;
long long pos;
long long ret;
bool st[N];
void dfs(int cnt)
{
	if(cnt == m)
	{
		ret = max(ret, path);
		return;
	}
	for(int i = 1; i <= m; i++)
	{
		if(st[i]) continue;
		pos += b[i];
		path += a[pos];
		st[i] = true;
		dfs(cnt + 1);
		//回溯
		path -= a[pos];
		pos -= b[i];
		st[i] = false;
	}

}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	pos = 1;
	path += a[1];
	dfs(0);
	cout << ret << endl;
	return 0;
}