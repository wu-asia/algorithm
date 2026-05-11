#include<iostream>
#include<unordered_map>
#include<utility>
#include<cstring>

using namespace std;

typedef long long LL;
const int N = 5000;
LL x, y;
LL p;
int T;

LL mp[N][N];

void fun()
{
	memset(mp, 0, sizeof mp);
	int t = 0;
	while(true)
	{
		if(mp[x][y] == 1)
		{
			cout << "error" << endl;
			return;
		}
		mp[x][y]++;
		t++;
		if(t % 2 == 1)
		{
			x = (x + y) % p;
			if(x == 0)
			{
				cout << 1 << endl;
				return;
			}
			
			
		}
		else
		{
			y = (x + y) % p;
			if(y == 0)
			{
				cout << 2 << endl;
				return;
			}
		}
	}
}
int main()
{
	cin >> T >> p;
	while(T--)
	{
		cin >> x >> y;
		fun();
	}
	return 0;
}