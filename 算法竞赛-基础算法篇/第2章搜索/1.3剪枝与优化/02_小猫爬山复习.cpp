#include<iostream>
#include<algorithm>

using namespace std;
const int N = 20;
int c[N], a[N];
int n, w;
int ret = N;
int cnt;

void dfs(int pos)
{
	if(ret <= cnt) return;
	if(pos > n)
	{
		ret = cnt;
		return;
	}

	for(int i = 1; i <= cnt; i++)
	{
		if(c[pos] + a[i] > w) continue;
		a[i] += c[pos];
		dfs(pos + 1);
		a[i] -= c[pos];
	}

	cnt++;
	a[cnt] = c[pos];
	dfs(pos + 1);
	a[cnt] = 0;
	cnt--;

}

bool cmp(int& x, int& y)
{
	return x > y;
}

int main()
{
	cin >> n >> w;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	sort(c + 1, c + 1 + n, cmp);
	dfs(1);
	cout << ret << endl;
	return 0;
}