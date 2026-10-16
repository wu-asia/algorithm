#include<iostream>
using namespace std;

typedef long long LL;

const int N = 15;
LL a[N], b[N];
int n;

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

LL qmul(LL a, LL b, LL p)
{
	LL sum = 0;
	while(b)
	{
		if(b & 1)
			sum = (sum + a) % p;
		a = (a + a) % p;
		b >>= 1;
	}
	return sum;
}

LL crt()
{
	LL M = 1;
	for(int i = 1; i <= n; i++)
		M *= a[i];
	LL ret = 0;
	for(int i = 1; i <= n; i++)
	{
		LL c = M / a[i];
		LL x, y;
		exgcd(c, a[i], x, y);
		x = (x % a[i] + a[i]) % a[i];
		//x为逆元
		ret = (ret + qmul(qmul(x, c, M), b[i], M)) % M;
	}
	return ret;
}
int main()
{	
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	cout << crt() << endl;

	return 0;
}