#include<iostream>

using namespace std;

typedef long long LL;
int k;
const int N = 15;
LL a[N], b[N];

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

void exgcd(LL a, LL b, LL& x, LL& y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return;
	}
	LL x1, y1;
	exgcd(b, a % b, x1, y1);
	x = y1, y = x1 - a / b * y1;
}


LL crt()
{
	LL M = 1;
	for(int i = 1; i <= k; i++)
		M *= b[i];
	LL ret = 0;
	for(int i = 1; i <= k; i++)
	{
		LL c = M / b[i];
		LL x, y;
		exgcd(c, b[i], x, y);
		x = (x % b[i] + b[i]) % b[i];
		ret = (ret + qmul(qmul(a[i], x, M), c, M)) % M;
	}

	return ret;
}

int main()
{
	cin >> k;
	for(int i = 1; i <= k; i++)
		cin >> a[i];
	for(int i = 1; i <= k; i++)
		cin >> b[i];

	for(int i = 1; i <= k; i++)
		a[i] = (a[i] % b[i] + b[i]) % b[i];
	
	cout << crt() << endl;
	return 0;
}