#include<iostream>

using namespace std;

typedef long long LL;

LL qpow(LL a, LL b)
{
	LL ret = 1;
	while(b)
	{
		if(ret > 1e9)
			return -1;
		if(b & 1)
		{
			if(ret > 1e9 / a)
				return -1;
			ret = ret * a;

		}
		if(b > 1)
		{
			if(a > 1e9 / a)
			return -1;
			a = a * a;
		}
		b >>= 1;
	}
	return ret;
}

int main()
{
	LL a, b;
	cin >> a >> b;
	cout << qpow(a, b) << endl;
	return 0;
}