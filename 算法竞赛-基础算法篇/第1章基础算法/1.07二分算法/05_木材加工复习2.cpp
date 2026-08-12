#include<iostream>

using namespace std;

int n, k;
typedef long long LL;
const int N = 1e5 + 10;
LL a[N];
bool check(LL x)
{
	LL ret = 0;
	for(int i = 1; i <= n; i++)
	{
		ret += (a[i] / x);
	}
	return (ret >= k);
}
int main()
{
	cin >> n >> k;
	bool flag = false;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] >= k)
			flag = true;
	}
	int l = 0, r = 1e8;
	while(l < r)
	{
		LL mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}