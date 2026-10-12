#include<iostream>

using namespace std;
typedef long long LL;
inline LL read()
{
	char ch = getchar();
	int flag = 1;
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			flag = -1;
		ch = getchar();
	}
	LL ret = 0;
	while(ch >= '0' && ch <= '9')
	{
		ret = ret * 10 + (ch - '0');
		ch = getchar();
	}
	return ret * flag;
}

inline void print(LL sum)
{
	if(sum < 0)
	{
		putchar('-');
		sum = -sum;
	}
	if(sum > 9) print(sum / 10);
	putchar(sum % 10 + '0');
}

int main()
{
	LL n = read();
	LL ret = 0;
	for(int i = 1; i <= n; i++)
	{
		LL x; 
		x = read();
		ret += x;
	}
	print(ret);
	return 0;
}