#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e7 + 10;
bool st[N];
LL p[N], phi[N];
LL cnt;

void get_phi()
{
	int n = 1e7;
	phi[1] = 1;
	for(LL i = 2; i <= n; i++)
	{
		if(!st[i])
		{
			phi[i] = i - 1;
			p[++cnt] = i;
		}
		for(LL j = 1; i * p[j] <= n; j++)
		{
			LL x = i * p[j];
			st[x] = true;
			if(i % p[j] == 0)
			{
				phi[x] = phi[i] * p[j];
				break;
			}
			else
			{
				phi[x] = phi[i] * (p[j] - 1);
			}
		}
	}
}

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

LL dfs(LL p)
{
	if(p == 1) return 0;
	return qpow(2, dfs(phi[p]) + phi[p], p);
}
int main()
{
	int T;
	cin >> T;
	get_phi();
	while(T--)
	{
		int p;
		cin >> p;
		cout << dfs(p) << endl;
	}
	return 0;
}