// #include<iostream>
// using namespace std;

// const int N = 2e3 + 10;
// const int M = 1e3 + 10;
// const int MOD = 1e8;

// int a[N], f[N][M];
// int n, m;
// int main()
// {
// 	cin >> n >> m;
// 	for(int i = 1; i <= n; i++)
// 		cin >> a[i];
// 	f[0][0] = 1;
// 	for(int i = 1; i <= n; i++)
// 	{
// 		for(int j = 0; j <= m; j++)
// 		{
// 			f[i][j] = (f[i - 1][j] + f[i - 1][((j - a[i] % m) % m + m) % m]) % MOD;
// 		}
// 	}

// 	cout << f[n][0] - 1 << endl;
// 	return 0;
// }


#include<iostream>
using namespace std;

const int N = 2e3 + 10;
const int M = 1e3 + 10;
const int MOD = 1e8;

int a[N], f[M];
int n, m;
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	f[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = m; j >= 0; j--)
		{
			f[j] = (f[j] + f[((j - a[i] % m) % m + m) % m]) % MOD;
		}
	}

	cout << f[0] - 1 << endl;
	return 0;
}