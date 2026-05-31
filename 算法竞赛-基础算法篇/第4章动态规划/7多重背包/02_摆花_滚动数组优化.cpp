//最值问题时会出现非法值类如-INF和INF
//而方案数则没有
#include<iostream>
using namespace std;

const int MOD = 1e6 + 7;
const int N = 110;

int n, m;
int a[N];
int f[N];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	f[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = m; j >= 0; j--)
		{
			for(int k = 1; k <= j && k <= a[i]; k++)
					f[j] = (f[j] + f[j - k]) % MOD;
		}
	}
	cout << f[m] << endl;
	return 0;
}