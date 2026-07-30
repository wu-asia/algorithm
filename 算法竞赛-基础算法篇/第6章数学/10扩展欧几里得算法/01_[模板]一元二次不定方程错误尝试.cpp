#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;
const int INF = 1e9 + 10;

LL exgcd(LL a, LL b, LL& x, LL & y)
{
	if(b == 0)
	{
		x = a, y = 0;
		return a;
	}
	LL x1, y1;
	LL d = exgcd(b, a % b, x1, y1);
	x = y1, y = x1 - a / b * y1;
	return d;
}

LL func(LL a, LL b, LL x, LL y, LL d, LL& max_x, LL& max_y, LL& min_x, LL& min_y)
{
	LL cnt = 0;
	for(LL k = - d / b * x; k <= d / a * y; k++)
	{
		if(k == 0) continue;
		LL x1 = x + b / d * k, y1 = y - a / d * k;
		max_x = max(x1, max_x);
		max_y = max(y1, max_y);
		min_x = min(x1, min_x);
		min_y = min(y1, min_y);
		cnt++;
	}
	return cnt;
}


int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		LL a, b, c, x, y;
		cin >> a >> b >> c;
		LL d = exgcd(a, b, x, y);
		if(c % d != 0)
		{
			cout << -1 << endl;
		}
		else
		{
			LL max_x = 0, max_y = 0, min_x = INF, min_y = INF, cnt;
			cnt = func(a, b, x, y, d, max_x, max_y, min_x, min_y);
			if(cnt)
			{
				cout << cnt << " " << min_x << " " << min_y << " " << max_x << " " << max_y << endl;
			}
			else
			{
				cout << x << " " << y << endl;
			}
		}
	}
	return 0;
}