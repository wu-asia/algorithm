#include<iostream>

using namespace std;
typedef long long LL;

const int N = 1e8 + 10;
LL n, q;
bool st[N];
LL cnt, p[N];

int main()
{
	cin >> n >> q;
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])
		{
			p[++cnt] = i;
		}
		for(LL j = 1; i * p[j] <= n; j++)
		{
			st[i * p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}

	while(q--)
	{
		int x; cin >> x;
		cout << p[x] << endl;
	}
	return 0;
}