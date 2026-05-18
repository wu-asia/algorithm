#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
LL m, n;
LL a[N], b[N];
LL ret;
int main()
{
	cin >> m >> n;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	sort(a + 1, a + 1 + m);
	for(int i = 1; i <= n; i++)
	{
		LL num = b[i];
		auto up = upper_bound(a + 1, a + 1 + m, num);
		auto low = lower_bound(a + 1, a + 1 + m, num);
		ret += min(abs(b[i] - *(up - 1)), abs(b[i] - *low));
	}
	cout << ret << endl;
	return 0;
}