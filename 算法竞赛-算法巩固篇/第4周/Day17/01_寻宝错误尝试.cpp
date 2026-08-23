#include<iostream>

using namespace std;

const int N = 1e4 + 10;
const int MOD = 20123;

int n, m;
int a[N], b[N];
int cnt[N][N];
int pos;
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i] >> b[i];
		int j = i / m + 1;
		if(a[i])
			cnt[i / m + 1][i % m - 1]++;
	}
	cin >> pos;
	int j = pos;
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		int t = (i - 1) * m + j;
		if(a[t])
		{
			ret = (ret + b[t]) % MOD;
			continue;
		}
		else
		{
			t = b[i] % cnt[i][t];
			if(t == 0)
				t = m;
			ret = (ret + b[t]) % MOD;
		}
	}
	
	cout << ret << endl;

	return 0;

}