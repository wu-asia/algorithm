#include<iostream>
#include<string>
#include<cmath>

using namespace std;
const int N = 2e3 + 10;
int f[N][N];
string a, b;
int main()
{
	cin >> a >> b;
	int n = a.size(), m = b.size();
	a = " " + a, b = " " + b;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i] == b[j])
				f[i][j] = f[i - 1][j - 1] + 1;
			else
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}
	cout << abs(n - f[n][m]) << endl;
	return 0;
}