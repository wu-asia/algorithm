#include<iostream>

using namespace std;
typedef long long LL;
int n;
int main()
{
	LL x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> n;
	LL ret1 = 0, ret2 = 0;

	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		LL d1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
		LL d2 = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
		if(d1 <= d2)
		{
			ret1 = max(ret1, d1);
		}
		else
		{
			ret2 = max(ret2, d2);
		}
	}
	cout << ret1 + ret2 << endl;
	return 0;
}