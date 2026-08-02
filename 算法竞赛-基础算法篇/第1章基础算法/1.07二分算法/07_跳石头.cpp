#include<iostream>

using namespace std;

typedef long long LL;
const int N = 5e4 + 10;
LL l, n, m;
LL a[N];

LL calc(LL x)
{
	LL ret = 0;
	for(int i= 0; i <= n; i++)
	{
		int j = i + 1;
		while(j <= n && a[j] - a[i] < x) j++;
		ret += j - i - 1;
		i = j - 1;
	}
	return ret;
}
int main()
{
	cin >> l >> n >> m;
	//l长度
	//n岩石数量
	//m搬走的数量
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	a[++n] = l;
	LL left = 1, right = 1e9;
	while(left < right)
	{
		LL mid = (left + right + 1) / 2;
		if(calc(mid) <= m) left = mid;
		else right = mid - 1;
	}
	cout << left << endl;
	return 0;
}

