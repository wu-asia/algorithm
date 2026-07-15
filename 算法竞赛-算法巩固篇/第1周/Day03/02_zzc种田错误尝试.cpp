#include<iostream>

using namespace std;

typedef long long LL;
LL x, y;

LL dfs(LL x, LL y)
{
	if(x == y) return 4 * x;
	LL ret = 0;
	if(x > y)
	{
		ret += 4 * y;
		ret += dfs(x - y, y);
	}
	if(x < y)
	{
		ret += 4 * x;
		ret += dfs(x, y - x);
	}
	return ret;
}
int main()
{
	cin >> x >> y;
	cout << dfs(x, y) << endl;
	return 0;
}