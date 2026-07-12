#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;
int n;
LL a[N], f[N];

LL dfs(int left, int right)
{
	if(left >= right) return a[left];
	LL ret = -1e6;
	int mid = (left + right) / 2;
	ret = max(dfs(left, mid), dfs(mid + 1, right));
	LL l = -1e6, r = -1e6;
	for(int i = left; i <= mid; i++)
		l = max(l, f[mid] - f[i - 1]);
	for(int i = mid + 1; i <= right; i++)
		r = max(r, f[i] - f[mid]);
	ret = max(ret, l + r);
	return ret;
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i] = a[i] + f[i - 1];
	}
	cout << dfs(1, n) << endl;
	return 0;
}