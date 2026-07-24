#include<iostream>

using namespace std;
typedef long long LL;
LL gcd(LL a, LL b)
{
	if(!b) return a;
	return gcd(b, a % b);
}

LL x, y, z;
int main()
{
	cin >> x >> y >> z;
	cout << gcd(x, gcd(y, z)) << endl;
	return 0;
}