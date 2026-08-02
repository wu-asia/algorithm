#include<iostream>

using namespace std;
typedef long long LL;
bool is_prime(LL n)
{
	if(n <= 1) return false;
	if(n == 2) return true;
	for(LL i = 2; i <= n / i; i++)
	{
		if(n % i == 0) return false;
	}
	return true;
}

int n;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		LL x;
		cin >> x;
		if(is_prime(x))
			cout << x << " ";
	}
	cout << endl;
	return 0;
}