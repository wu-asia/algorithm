#include<iostream>
#include<climits>

using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
int n;

LL a[N];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	LL sum = 0, ret = LLONG_MIN;
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