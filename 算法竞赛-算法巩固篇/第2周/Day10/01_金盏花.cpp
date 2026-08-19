#include<iostream>
#include<cmath>
typedef long long LL;
using namespace std;

LL y, z;
int main()
{
	cin >> y >> z;
	LL ret = 1e12 + 10;
	for( LL i = 100000; i <= 999999; i++)
	{
		ret = min(ret, abs((i * 1000000 + y) - z));
	}
	cout << ret << endl;
	return 0;
}