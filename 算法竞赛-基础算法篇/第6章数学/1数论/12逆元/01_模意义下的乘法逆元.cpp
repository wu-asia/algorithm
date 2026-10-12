#include<iostream>

using namespace std;

const int N = 3e6 + 10;

typedef long long LL;
LL n, p;
LL inv[N];

void get_inv()
{
	inv[1] = 1;
	for(LL i = 2; i <= n; i++)
	{
		inv[i] = p - p / i * inv[p % i] % p;
	}
}

int main()
{
	cin >> n >> p;
	get_inv();
	for(int i = 1; i <= n; i++)
		printf("%d\n", inv[i]);

	return 0;
}