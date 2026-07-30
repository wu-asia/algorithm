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
	LL T;
	while(T--)
	{
		LL a, b, c, x, y;
		LL d;
		scanf("%d%d%d", &a, &b, &c);
		d = exgcd(a, b, x, y);
		if(c % d) printf("-1\n");
		else
		{
			x = c / d * x, y = c / d * y;
			LL k1 = b / d, k2 = a / d;
			x = (x % k1 + k1) % k1;
			x = (x == 0 ? k1 : x);
			y = (c - a * x) / b;
			LL maxx, maxy, minx, miny;
			if(y > 0) //4个解
			{
				minx = x, maxy = y;
				y = (y % k2 + k2) % k2;
				y = (y == 0 ? k2 : y);
				maxx = (c - b * y) / a;
				miny = y;
				LL cnt = (maxx - minx) / k1 + 1;
				printf("%lld %lld %lld %lld %lld\n", cnt, minx, miny, maxx, maxy);
			}
			else
			{
				minx = x;
				y = (y % k2 + k2) % k2;
				y = (y == 0 ? k2 : y);
				miny = y;
				printf("%lld %lld\n", minx, miny);	
			}
		}
	}
	return 0;
}