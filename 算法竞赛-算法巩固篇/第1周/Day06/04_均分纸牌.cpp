#include<iostream>

using namespace std;

const int N = 110;
int a[N];
int n;
int main()
{
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sum /= n;
	//cout << sum << endl;
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		int d = a[i] - sum;
		if(d) ret++;
		a[i + 1] += d;
	}
	cout << ret << endl;
	return 0;
}