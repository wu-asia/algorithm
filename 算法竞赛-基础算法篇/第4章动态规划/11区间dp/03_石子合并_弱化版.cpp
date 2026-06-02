#include<iostream>
#include<cstring>

using namespace std;
const int N = 310;
int n;
int m[N];
int f[N][N];
int sum[N]; //前缀和数组
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> m[i];
		sum[i] = sum[i - 1] + m[i];
	}
	memset(f, 0x3f, sizeof f);
	for(int i = 0; i <= n; i++)
		f[i][i] = 0;
	for(int len = 2; len <= n; len++)
	{
		for(int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			//使用前缀和求解区间和
			int t = sum[j] - sum[i - 1];
			//枚举中间分割点
			for(int k = i; k < j; k++)
			{
				//将区间分割为[i, k], [k + 1, j]
				//最后的结果是左区间的最优解加上右区间的最优解加上区间和
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + t);
			}
		}
	}
	// for(int i = 1; i <= n; i++)
	// {
	// 	for(int j = 1; j <= n; j++)
	// 		cout << f[i][j] << " ";
	// 	cout << endl;
	// }
	cout << f[1][n] << endl;
	return 0;
}