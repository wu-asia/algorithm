#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
LL n, c;
LL a[N], ret;
int main()
{
	//lower_bound(iterator.begin(), iterator.end(), number);
	//表示的是找出这个数组中第一个是number的位置
	//upper_bound(iterator.begin(), iterator.end(), number);
	//表示的是找出这个数组中最后一个是number的后一位
	cin >> n >> c;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 2; i <= n; i++)
	{
		LL b = a[i] - c;
		ret += upper_bound(a + 1, a + i, b) - lower_bound(a + 1, a + i, b);
	}
	cout << ret << endl;
	return 0;
}