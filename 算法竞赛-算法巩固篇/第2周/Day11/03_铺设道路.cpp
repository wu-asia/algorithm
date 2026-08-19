#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > a[i - 1])
			ret += (a[i] - a[i - 1]);
	}
	cout << ret << endl;
	return 0;
}