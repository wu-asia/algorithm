#include<iostream>
#include<cmath>

using namespace std;
typedef long long LL;

LL l, r;
const int N = 1e6 + 10;
bool st[N];
LL p[N], cnt;
bool ret[N];

void get_prime()
{
	LL n = sqrt(r);
	for(int i = 2; i <= n; i++)
	{
		if(!st[i]) p[++cnt] = i;
		for(LL j = 1; i * p[j] <= n; j++)
		{
			st[i * p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
}

int main()
{
	cin >> l >> r;
	get_prime();
	l = (l == 1 ? 2 : l);

	for(int i = 1; i <= cnt; i++)
	{
		LL x = p[i];
		for(LL j = max(2 * x, (l + x - 1) / x * x); j <= r; j += x)
		{
			ret[j - l] = true;
		}
	}

	LL sum = 0;
	for(LL i = l; i <= r; i++)
	{
		if(!ret[i - l]) sum++;
	}

	cout << sum << endl;
	return 0;
}