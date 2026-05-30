#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 110;
const int M = 5e4 + 10;
int n, h;
//n是n家公司，h是要采购的干草
int p[N], c[N];
//p[i]表示第i公司买干草包的重量
//c[i]表示需要开销多少元
int f[N][M];
//f[i][j]表示从[1, i]中挑选出重量大于等于j的干草的最小开销
int main()
{
	cin >> n >> h;
	for(int i = 1; i <= n; i++)
		cin >> p[i] >> c[i];
	memset(f, 0x3f, sizeof f);
	//f[0][0]表示的是什么都不选是重量为0，所需要的最小开销是0
	f[0][0] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= h; j++)
		{
			//后面选i处的干草有两种情况
			//情况1：
			//j >= p[i]时，是使用f[i][j - p[i]]处的方案之后在加上c[i]的价值
			//情况2：
			//当j < p[i]时，p[i]就已经满足了大于等于j的情况，只需要使用f[i][0]处的方案即可
			//f[i][0]表示之前未选择干草的方案
			f[i][j] = min(f[i - 1][j], f[i][max(0, j - p[i])] + c[i]);
		}
	}
	// for(int i = 0; i <= n; i++)
	// {
	// 	for(int j = 0; j <= h; j++)
	// 	{
	// 		cout << f[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << f[n][h] << endl;
	return 0;
}