#include<iostream>

const int N = 1e7 + 10;

using namespace std;
typedef long long LL;

int cnt, p[N];
bool st[N];
int phi[N];
LL sum[N];
int n;
void get_phi()
{
	phi[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])
		{
			p[++cnt] = i;
			phi[i] = i - 1;
		}
		for(int j = 1; 1ll * i * p[j] <= n; j++)
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
	get_phi();
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + phi[i];
	LL ret = 0;
	// for(int i = 1; i <= cnt; i++)
	// 	cout << p[i] << " ";
	//cout << endl;
	for(int i = 1; i <= cnt; i++)
	{
			ret += (2 * sum[n / p[i]] - 1);
	}
	cout << ret << endl;
	return 0;
}