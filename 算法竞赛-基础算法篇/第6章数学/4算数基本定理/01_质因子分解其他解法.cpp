#include<iostream>
#include<cmath>

using namespace std;

const int N = 1e6 + 10;
int n;
int cnt[N];

void deprime(int x)
{
	for(int i = 2; i <= sqrt(x); i++)
	{
		while(x % i == 0)
		{
			x /= i;
			cnt[i]++;
		}
	}
	if(x > 1)
		cnt[x]++;
}

int ind, p[N];
bool st[N];
void prime(int x)
{
	for(int i = 2; i <= x; i++)
	{
		if(!st[i])
			p[++ind] = i;
		for(int j = 1; i * p[j] <= n; j++)
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
	for(int i = 2; i <= n; i++)
	{
		deprime(i);
	}

	prime(n);

	for(int i = 2; i <= p[ind]; i++)
	{
		if(!cnt[i]) continue;
		cout << i << " " << cnt[i] << endl;
	}
	return 0;
}