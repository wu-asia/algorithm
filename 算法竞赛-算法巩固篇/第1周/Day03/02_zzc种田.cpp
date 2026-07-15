#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;
LL x, y;
int main()
{
	cin >> x >> y;
	LL ret = 0;
	while(x && y)
	{
		LL cnt = x / y;
		ret += cnt * 4 * y;
		x %= y;
		swap(x, y);
	}
	cout << ret << endl;
	return 0;
}