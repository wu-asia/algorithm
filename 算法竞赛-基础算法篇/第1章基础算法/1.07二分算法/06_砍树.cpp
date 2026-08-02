#include<iostream>

using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
LL n, m;
LL a[N];

LL calc(LL x)
{
	LL cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		LL dif = a[i] - x;
		dif = dif > 0 ? dif : 0;
		cnt += dif;
	}
	return cnt;
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	//left, right是表示的砍树的高度
	LL left = 0, right = 2e9;
	while(left < right)
	{
		int mid = (left + right + 1) / 2;
		if(calc(mid) >= m) left = mid;
		else right = mid - 1;
	}
	cout << left << endl;
	return 0;
}