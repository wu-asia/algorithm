#include<iostream>
using namespace std;

const int N = 50;
typedef long long LL;
LL n, m;
LL f[N][N]; //f[i][j]表示第i次传球，传到第j个人手中的方案数
int main()
{
	cin >> n >> m;
	f[0][1] = 1;
	for(int i = 1; i <= m; i++)
	{
		f[i][1] = f[i - 1][2] + f[i - 1][n];
		for(int j = 2; j < n; j++)
			f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
		f[i][n] = f[i - 1][n - 1] + f[i - 1][1];
	}
	cout << f[m][1] << endl;

	return 0;
}