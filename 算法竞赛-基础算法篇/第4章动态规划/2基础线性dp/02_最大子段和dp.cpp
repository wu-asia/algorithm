#include<iostream>
#include<algorithm>

using namespace std;
const int N = 2e5 + 10;
int a[N];
int n;
long long f[N];
int main()
{
	cin >> n;
	f[0] = 0;
	long long ret = LLONG_MIN;
	for(int i = 1; i <= n; i++)
	{
		long long x;
		cin >> x;
		f[i] = max(f[i - 1] + x, x);
		ret = max(ret, f[i]);
	}
	cout << ret << endl;
	return 0;
}