#include<iostream>

using namespace std;

const int N = 4e4 + 10;
typedef long long LL;
int cnt, p[N];
int phi[N];
bool st[N];
int n;

void get_phi()
{
	phi[1] = 1;
	for(LL i = 2; i <= n; i++)
	{
		if(!st[i])
		{
			p[++cnt] = i;
			phi[i] = i - 1;
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

int main()
{
	cin >> n;
	LL ret = 0;
	get_phi();
	// for(int i = 1; i <= n; i++)
	// 	cout << phi[i] << " ";
	// cout << endl;
	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	else
	{
		for(int i = 1; i < n; i++)
			ret += phi[i];
		ret *= 2;
		ret++;
		cout << ret << endl;
	}
	return 0;
}