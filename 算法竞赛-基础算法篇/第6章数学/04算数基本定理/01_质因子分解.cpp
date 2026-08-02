#include<iostream>
#include<cmath>

using namespace std;

const int N = 1e4 + 10;
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

int main()
{
	cin >> n;
	for(int i = 2; i <= n; i++)
	{
		deprime(i);
	}


	for(int i = 2; i <= n; i++)
	{
		if(!cnt[i]) continue;
		cout << i << " " << cnt[i] << endl;
	}
	return 0;
}