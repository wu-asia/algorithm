#include<iostream>

using namespace std;

typedef long long LL;

LL n, sum;
int main()
{
	cin >> n;
	for(int i = 1; i <= n / 2; i++)
		sum += n / i;
	sum += (n + 2 - 1) / 2;
	cout << sum << endl;
	return 0;
}