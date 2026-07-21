#include<iostream>

using namespace std;

const int N = 50;
int n;
long long f[N];

int main()
{
	cin >> n;
	f[0] = 1;
	int sum = (1 + n) * n / 2;
	if(sum & 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		for(int j = sum / 2; j >= i; j--)
		{
				f[j] = f[j] + f[j - i];
		}
	cout << f[sum / 2] / 2 << endl;
	return 0;
}