#include<iostream>
#include<string>

using namespace std;

const int N = 1e6 + 10;
int a[N], b, c[N];
int la, lc;

typedef long long LL;
void div(int c[], int a[], int b)
{
	LL t= 0;
	for(int i = la - 1; i >= 0; i--)
	{
		t = t * 10 + a[i];
		c[i] = t / b;
		t %= b;
	}

	while(lc > 1 && c[lc - 1] == 0) 
		lc--;
}
int main()
{
	string x;
	cin >> x;
	cin >> b;
	
	la = x.size();
	for(int i = 0; i < la; i++)
		a[la - 1 - i] = x[i] - '0';
	
	lc = la;
	div(c, a, b);
	for(int i = lc - 1; i >= 0; i--)
		cout << c[i];
	return 0;
}