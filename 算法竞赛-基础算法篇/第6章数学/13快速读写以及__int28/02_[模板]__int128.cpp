#include<iostream>

using namespace std;

typedef __int128 LL;

inline LL read()
{
	char ch = getchar();
	int flag = 1;
	LL ret = 0;
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			flag = -flag;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		ret = ret * 10 + (ch - '0');
		ch = getchar();
	}
	return ret * flag;
}

inline void print(LL x)
{
	if(x < 0)
	{
		putchar('-');
		x = -x;
	}
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int main()
{
	__int128 x = read();
	print(x);

	return 0;
}