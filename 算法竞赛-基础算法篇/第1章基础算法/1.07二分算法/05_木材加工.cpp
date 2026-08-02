#include<iostream>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL n, k;
LL a[N];
//calc的作用是将

LL calc(LL x)
{
	LL cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		cnt += a[i] / x;
	}
	return cnt;
}
int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	//left, right表示的是Li中的所有情况
	LL left = 0, right = 1e8;
	while(left < right)
	{
		LL mid = (left + right + 1) / 2;
		if(calc(mid) >= k) left = mid;
		else right = mid - 1;
	}
	cout << left << endl;
	return 0;
}

