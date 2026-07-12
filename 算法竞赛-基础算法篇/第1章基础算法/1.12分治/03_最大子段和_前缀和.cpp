#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
LL n, f[N];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		f[i] = x + f[i - 1];
	}

	LL ret = -0x3f3f3f3f, premin = 0;
	for(int i = 1; i <= n; i++)
	{
		ret = max(ret, f[i] - premin);
		premin = min(premin, f[i]);
	}
	cout << ret << endl;
	return 0;
}