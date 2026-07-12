#include<iostream>

using namespace std;

const int N = 2e5 + 10;
int a[N];
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ret = -0x3f3f3f3f, sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum += a[i];
		ret = max(ret, sum);

		if(sum < 0)
			sum = 0;
	}
	cout << ret << endl;
	return 0;
}