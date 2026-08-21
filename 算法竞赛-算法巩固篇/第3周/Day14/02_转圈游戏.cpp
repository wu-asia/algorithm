#include<iostream>

using namespace std;

typedef long long LL;

LL n, m, k, x;

LL qpow(LL a, LL b, LL p)
{
	LL ret = 1;
	while(b)
	{
		if(b & 1)
			ret = (ret * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return (ret % p);
}

LL get_phi(LL n)
{
	LL ret = n;
	for(LL i = 2; i <= n / i; i++)
	{
		if(n % i == 0)
		{
			ret = ret / i * (i - 1);
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1) ret = ret / n * (n - 1);
	return ret;
}

int main()
{
	cin >> n >> m >> k >> x;
	LL phi = get_phi(n);
	if(k < phi)
		cout << (x % n + (m % n * qpow(10, k, n))) % n << endl;
	else
		cout << (x % n + (m % n * qpow(10, k % phi + phi, n) % n)) % n << endl;
	return 0;
}