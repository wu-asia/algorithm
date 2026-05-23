#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1e5 + 10;
int a[N];
typedef long long LL;
int n;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	LL sum = 0;
	for(int i = 1; i <= n; i++)
		sum += abs(a[i] - a[(1 + n) / 2]);
	cout << sum << endl;
	return 0;
}