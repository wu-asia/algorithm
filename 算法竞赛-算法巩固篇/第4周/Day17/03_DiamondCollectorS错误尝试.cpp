#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 5e4 + 10;
int n, k;
const int M = 1e3 + 10;
int a[N];
int d[M][M];
int main()
{
	cin >> n >> k;
	memset(d, 0x3f, sizeof d);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			d[i][j] = abs(a[i] - a[j]);
		}
	}
	int ret1 = 0, f1 = 0;
	for(int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for(int j = 1; j <= n; j++)
		{
			if(d[i][j] <= k)
				cnt++;
		}
		if(ret1 < cnt)
		{
			f1 = i;
			ret1 = cnt;
		}
	}
	int ret2 = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i == f1) continue;
		int cnt = 0;
		for(int j = 1; j <= n; j++)
		{
			if(d[i][j] <= k)
				cnt++;
		}
		ret2 = max(ret2, cnt);	
	}
	cout << ret1 + ret2 << endl;
	return 0;
}