#include<iostream>

using namespace std;
typedef long long LL;

const int N = 1e7 + 10;

LL gcd(LL x, LL y)
{
	return y == 0 ? x : gcd(y, x % y);
}

LL cnt, p[N];
bool st[N];
int n;
void get_prime()
{
	st[1] = true;
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])
			p[++cnt] = i;
		for(int j = 1; 1ll * i * p[j] <= n; j++)
		{
			st[i * p[j]] = true;
			if(i % p[j] == 0)
				break;
		}
	}
}

int main()
{

	// cout << gcd(3, 3) << endl;
	cin >> n;
	LL ret = 0;
	get_prime();
	// for(int i = 1; i <= cnt; i++)
	// 	cout << p[i] << " ";
	// cout << endl;
	// for(int i = 1; i <= n; i++)
	// 	cout << st[i] << " ";
	//cout << endl;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 2; j <= n; j++)
		{
			if(!st[gcd(i, j)])
				ret++;
		}
	}
	cout << ret << endl;
	return 0;
}