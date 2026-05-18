#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL a[N], b[N];
int n, m;
LL ret;
LL find(LL x)
{
	int left = 1, right = m;
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(a[mid] >= x) right = mid;
		else left = mid + 1;
	}
	return left;
}
int main()
{
	cin >> m >> n;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	a[0] = INT_MIN;
	sort(a + 1, a + 1 + m);
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	for(int i = 1; i <= n; i++)
	{
		LL t = b[i];
		int pos = find(t);
		ret += min(abs(a[pos] - t), abs(a[pos - 1] - t));
	}
	cout << ret << endl;
	return 0;
}