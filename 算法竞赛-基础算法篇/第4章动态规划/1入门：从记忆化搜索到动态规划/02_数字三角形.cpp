#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;
int a[N][N];
int f[N]; //若出现负数，则需要初始化为负无穷的大小 memset(f, 0xcf, sizeof f);
int r;
int ret;

int main()
{
	cin >> r;
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= i; j++)
			cin >> a[i][j];
	// for(int i = 1; i <= r; i++)
	// {
	// 	for(int j = 1; j <= i; j++)
	// 	{
	// 		f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
	// 	}
	// }

	// for(int k = 1; k <= r; k++)
	// 	ret = max(ret, f[r][k]);
	// cout << ret << endl;

	for(int i = 1; i <= r; i++)
	{
		for(int j = i; j >= 1; j--)
		{
			f[j] = max(f[j], f[j - 1]) + a[i][j];
		}
	}

	for(int k = 1; k <= r; k++)
		ret = max(ret, f[k]);
	cout << ret << endl;
	return 0;
}