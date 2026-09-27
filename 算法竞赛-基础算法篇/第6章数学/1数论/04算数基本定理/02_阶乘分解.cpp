#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;
int n;
int p[N];
bool st[N];
int cnt;
void get_prime()
{
	for(LL i = 2; i <= n; i++)
	{
		if(!st[i]) p[++cnt] = i;
		for(LL j = 1; i * p[j] <= n; j++)
		{
			st[i * p[j]] = true;
			if(p[j] % i == 0)
				break;
		}
	}
}

int main()
{
	cin >> n;
	get_prime();

	for(LL i = 1; i <= cnt; i++)
	{
		LL s = 0;
		for(LL j = p[i]; j <= n; j *= p[i])
		{
			s += n / j;
		}
		cout << p[i] << " " << s << endl;
	}
	return 0;
}