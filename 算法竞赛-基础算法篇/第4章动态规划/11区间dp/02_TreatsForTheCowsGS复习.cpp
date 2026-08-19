#include<iostream>

using namespace std;

int n;
const int N = 2e3 + 10;
int v[N];
int f[N][N];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	for(int len = 1; len <= n; len++)
	{
		for(int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			int d = (n - len + 1);
			f[i][j] = max(f[i + 1][j] + v[i] * d, f[i][j - 1] + v[j] * d);
		}
	}
	cout << f[1][n] << endl;
	return 0;
}