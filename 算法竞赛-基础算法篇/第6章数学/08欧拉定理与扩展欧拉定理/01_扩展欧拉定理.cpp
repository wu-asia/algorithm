#include<iostream>
#include<string>
#include<sstream>

using namespace std;

typedef long long LL;
LL a, m;
string b;

LL get_phi(LL n)
{
	LL ret = n;
	for(LL i = 2; i <= n / i; i++)
	{
		if(n % i == 0)
		{
			ret = ret / i * (i - 1);
			while(n % i == 0)
				n /= i;
		}
	}
	if(n > 1) ret = ret / n * (n - 1);
	return ret;
}

LL qpow(LL a, LL b, LL p)
{
	LL ret = 1;
	while(b)
	{
		if(b & 1) ret = a * ret % p;
		a = a * a % p;
		b >>= 1;
	}
	return ret % p;
}

string i2s(LL x)
{
	string s;
	stringstream ss;
	ss << x;
	ss >> s;
	return s;
}
int main()
{
	cin >> a >> m >> b;
	LL phi_m = get_phi(m);
	LL x = 0;
	for(int i = 0; i < b.size(); i++)
	{
		x = (x % phi_m * 10 % phi_m + (b[i] - '0')) % phi_m;
	}
	if(i2s(x) == b) cout << qpow(a, x, m) << endl;
	else cout << qpow(a, x + phi_m, m) << endl;
	return 0;
}