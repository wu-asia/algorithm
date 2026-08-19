// 错误尝试

#include<iostream>
#include<cmath>

typedef long long LL;
using namespace std;


LL x, y, z;

int cnt(LL x)
{
	int ret = 0;
	while(x)
	{
		ret++;
		x /= 10;
	}
	return ret;
}
int main()
{
	cin >> y >> z;
	if(z < 0)
	{
		cout << pow(10, 12) + y - z << endl;
	}
	if(cnt(z) == 12)
	{
		LL num = 0;
		for(int i = 0; i < 6; i++)
		{
			num += (z % 10) * pow(10, i);
			z /= 10;
		}
		if(num - y < 0)
			cout << num - y + 1000000 << endl;
		else
			cout << num - y << endl;
	}
	else if(cnt(z) > 6 && cnt(z) < 12)
	{
		LL num = 0;
		num = pow(10, 12) + y - z;
		cout << num << endl;
	}
	else if(cnt(z) <= 6)
	{
		LL num = 0;
		num = pow(10, 12) + y - z;
		cout << num << endl;
	}
	else if(cnt(z) > 12)
	{
		LL num = 0;
		for(int i = 0; i < 6; i++)
		{
			num += 9 * pow(10, i);
		}
		num += y;
		cout << num - z << endl;
	}
	return 0;
}