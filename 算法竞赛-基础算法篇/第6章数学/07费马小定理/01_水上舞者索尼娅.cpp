#include<iostream>

using namespace std;

typedef long long LL;

const LL MOD = 1e9 + 7;

LL n, k;

LL qpow(LL a, LL b, LL p)
{
	LL ret = 1;
	while(b)
	{
		if(b & 1) ret = ret * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ret % p;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> k;
		LL ret = qpow(k + 1, n + 1, MOD);
		ret = (ret - k - 1) * qpow(k, MOD - 2, MOD);
		ret = (ret % MOD + MOD) % MOD;
		cout << ret << endl;
	}
	return 0;
}