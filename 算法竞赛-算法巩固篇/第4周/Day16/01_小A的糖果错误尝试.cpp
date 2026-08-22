#include<iostream>

using namespace std;

const int N = 1e5 + 10;

typedef long long LL;
LL n, x;
LL a[N];
int main()
{
	cin >> n >> x;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ret = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] + a[i + 1] <= x) continue;
		int d = a[i] + a[i + 1] - x;
		a[i + 1] -= d;
		if(a[i + 1] < 0)
		{
			a[i] += a[i + 1];
			a[i + 1] = 0;
		}
		ret += d;
	}
	cout << ret << endl;
	return 0;
}