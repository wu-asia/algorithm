#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int m, n;
typedef long long LL;
const int N = 1e5 + 10;

LL a[N], b[N];

int binary_search(int x)
{
	int l = 1, r = m;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(a[mid] >= x) r = mid;
		else l = mid + 1;
	}
	if(l == 1)
		return abs(x - a[l]);
	else
		return min(abs(x - a[l]), abs(x - a[l - 1]));
}
int main()
{
	cin >> m >> n;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	for(int j = 1; j <= n; j++)
		cin >> b[j];
	sort(a + 1, a + 1 + m);
	LL ret = 0;
	for(int j = 1; j <= n; j++)
	{
		ret += binary_search(b[j]);
	}
	cout << ret << endl;
	return 0;	
}