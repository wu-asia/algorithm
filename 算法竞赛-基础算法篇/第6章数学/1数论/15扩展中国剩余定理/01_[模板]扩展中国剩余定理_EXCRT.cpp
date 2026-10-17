#include<iostream>

using namespace std;
typedef __int128 LL;

const int N = 1e5 + 10;
int n;
LL m[N], r[N];

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
LL exgcd(LL a, LL b, LL& x, LL& y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	LL d, x1, y1;
	d = exgcd(b, a % b, x1, y1);
	x = y1, y = x1 - a / b * y1;
	return d;
}

LL read()
{
	char ch = getchar();
	int flag = 1;
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			flag = -flag;
		ch = getchar();
	}
	LL ret = 0;
	while(ch >= '0' && ch <= '9')
	{
		ret = ret * 10 + (ch - '0');
		ch = getchar();
	}
	return flag * ret;
}

void print(LL x)
{
	if(x < 0)
	{
		x = -x;
		putchar('-');
	}
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
LL excrt()
{
	LL M = 1, ret = 0;
	for(int i = 1; i <= n; i++)
	{
		LL a = M, b = m[i], c = r[i] - ret;
		c = (c % b + b) % b;
		LL d, x, y;
		d = exgcd(a, b, x, y);
		if(c % d) return -1;
		LL k1 = b / d;
		x = qmul(x, c / d, k1);
		x = (x % k1 + k1) % k1;
		ret = ret + x * M;
		M = k1 * M;
		ret = (ret % M + M) % M;
	}
	return ret;
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		//cin >> m[i] >> r[i];
		m[i] = read();
		r[i] = read();
		r[i] = (r[i] % m[i] + m[i]) % m[i];
	}
	print(excrt());
	cout << endl;
	//cout << excrt() << endl;
	return 0;
}