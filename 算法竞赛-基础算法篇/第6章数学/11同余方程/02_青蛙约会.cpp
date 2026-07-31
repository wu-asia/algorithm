#include<iostream>

using namespace std;
typedef long long LL;

LL exgcd(LL a, LL b, LL& x, LL& y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}

	LL x1, y1, d;
	d = exgcd(b, a % b, x1, y1);
	x = y1, y = x1 - a / b * y1;
	return d;

}
int main()
{
	LL x, y, m, n, l;
	cin >> x >> y >> m >> n >> l;
	LL a = m - n, b = l, c = y - x;
	if(a < 0)
	{
		a = -a;
		c = -c;
	}
	LL x0, y0;
	LL d = exgcd(a, b, x0, y0);
	x0 = c / d * x0;
	y0 = c / d * y0;
	if(c % d)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		LL k = b / d;
		cout << (x0 % k + k) % k << endl;
	}
	return 0;
}