#include<iostream>
#include<cmath>

using namespace std;
int n;
int main()
{
	cin >> n;
	for(int i = n; i >= 0; i--)
	{
		int a;
		cin >> a;
		if(a == 0) continue;
		//1.符号
		if(a < 0) cout << "-";
		else if(n != i) cout << "+";
		//2.数字
		a = abs(a);
		if((a == 1 && i == 0) || a != 1)
		{
			if(i == 0) cout << a;
		}
		//3.系数
		if(i == 0) continue;
		else if(i == 1) cout << "x";
		else cout << "x^" << i;
	}
	return 0;
}