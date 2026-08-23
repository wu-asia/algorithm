#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 310;
int a[N];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 0, r = n;
	LL ret = 0;
	while(l < r)
	{

		ret += (a[r] - a[l]) * (a[r] - a[l]);
		l++;
		ret += (a[r] - a[l]) * (a[r] - a[l]);
		r--;
	}
	cout << ret << endl;
	return 0;
}