#include<iostream>

using namespace std;

int n, m;
const int N = 1e5 + 10;

typedef long long LL;
LL a[N];
bool check(LL x)
{
	LL sum = 0, cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		sum += a[i];
		if(sum > x)
		{
			cnt++;
			sum = a[i];
		}
	}
	return (cnt + 1 <= m);
}
int main()
{
	cin >> n >> m;
	LL l = 0, r = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		l = max(l, a[i]);
		r += a[i];
	}
	while(l < r)
	{
		LL mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}