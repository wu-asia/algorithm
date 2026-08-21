#include<iostream>

using namespace std;
typedef long long LL;

int main()
{
	LL n, m, v;
	cin >> n >> m >> v;
	if(m < (n - 1) || m > (n - 1) * (n - 2) / 2 + 1)
	{
		cout << -1 << endl;
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			if(i == v) continue;
			cout << i << " " << v << endl;
		}
		int d = 1;
		if(d == v) d = 2;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j < i; j++)
			{
				if(!m) return 0;
				if(i == j) continue;
				if(i == v || i == d) continue;
				if(j == v || j == d) continue;
				cout << i << " " << j << endl;
				m--;
			}
		}
	}
	return 0;
}