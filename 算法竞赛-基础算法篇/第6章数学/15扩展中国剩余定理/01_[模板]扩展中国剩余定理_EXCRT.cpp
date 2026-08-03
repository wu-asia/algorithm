#include<iostream>

using namespace std;
typedef long long LL;

const int N = 15;
int n;
LL m[N], r[N];

LL exgcd(LL a, LL b, LL& x, LL& y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return d;
	}
	LL d, x1, y1;
	d = exgcd(b, a % b, x1, y1);
	x = y1, y = x1 - a / b * y1;
	return d;
}

LL excrt()
{
	LL M = 1, ret = 0;
	for(int i = 1; i <= n; i++)
	{
		LL a = M, b = m[i], c = r[i] - ret;
		LL d, x, y;
		d = exgcd(a, b, x, y);
		if(c % d) return -1;
		LL k1 = b / d;
		
	}
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> m[i] >> r[i];
		r[i] = (r[i] % m[i] + m[i]) % m[i];
	}
	cout << excrt() << endl;
	return 0;
}