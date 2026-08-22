#include<iostream>


using namespace std;

const int N = 1e5 + 10;
int n, x;
int a[N];
int main()
{
	cin >> n >> x;
	LL sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		LL d = a[i] + a[i - 1] - x;
		if(d > 0)
		{
			sum += d;
			a[i] = x - a[i - 1];
		}
	}
	cout << sum << endl;
	return 0;
}