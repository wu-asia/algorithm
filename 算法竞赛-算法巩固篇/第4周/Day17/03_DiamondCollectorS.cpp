#include<iostream>
#include <algorithm>
using namespace std;

const int N = 5e4 + 10;
int n, k;
int a[N];
int f[N], g[N];
int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int l = 1, r = 1; r <= n; r++)
	{
		while(a[r] - a[l] > k)
			l++;
		f[r] = max(f[r - 1], r - l + 1);
	}
	for(int l = n, r = n; l >= 1; l--)
	{
		while(a[r] - a[l] > k)
			r--;
		g[l] = max(g[l + 1], r - l + 1);
	}
	int ret = 0;
	for(int i = 2; i <= n; i++)
	{
		ret = max(ret, f[i - 1] + g[i]);
	}
	cout << ret << endl;
	return 0;
}