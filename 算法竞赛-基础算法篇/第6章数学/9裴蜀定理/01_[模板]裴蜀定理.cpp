#include<iostream>
#include<cmath>

using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int n;
	cin >> n;
	int x;
	if(n == 1)
	{
		cin >> x;
		cout << abs(x) << endl;
	}
	int a, b;
	cin >> a >> b;
	x = gcd(abs(a), abs(b));
	for(int i = 1; i <= n - 2; i++)
	{
		int c; cin >> c;
		x = gcd(abs(x), abs(c));
	}
	cout << x << endl;
	return 0;
}