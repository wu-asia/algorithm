#include<iostream>
#include<algorithm>

using namespace std;

int n;
const int N = 2e5 + 10;
int a[N];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	n = unique(a + 1, a + n + 1) - (a + 1);

	if(n == 1)
		cout << -1 << endl;
	else if(n == 2)
		cout << a[2] % a[1] << endl;
	else
		cout << max(a[n - 2], a[n] % a[n - 1]) << endl;
	return 0;
}