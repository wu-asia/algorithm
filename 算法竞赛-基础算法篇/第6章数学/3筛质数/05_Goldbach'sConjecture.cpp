#include<iostream>
#include<set>

using namespace std;
typedef long long LL;
set<int> mp;
const int N = 1e6 + 10;
bool st[N];
LL p[N];
void get_prime(int n)
{
	for(LL i = 2; i <= n; i++)
	{
		if(!st[i] && !mp.count(i))
			mp.insert(i);
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
	int n;
	while(cin >> n && n)
	{
		get_prime(n);
		for(auto e : mp)
		{
			if(e == 2) continue;
			LL x = n - e;
			if(mp.count(x))
			{
				cout << n << " = " << e << " + " << x << endl;
				break;
			}
		}
	}
	return 0;
}