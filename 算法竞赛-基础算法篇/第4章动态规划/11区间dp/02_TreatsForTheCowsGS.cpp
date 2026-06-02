#include<iostream>
#include<string>

using namespace std;

const int N = 2e3 + 10;
int n;
int v[N];
int f[N][N];
//f[i][j]表示的是[i, j]区间内的最大价值
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
			f[i][j] = max(f[i + 1][j] + v[i] * (n - len + 1), f[i][j - 1] + v[j] * (n - len + 1));
		}
	}
	cout << f[1][n] << endl;
	return 0;
}