//使用滚动数组优化的时候需要使用的是前面的值和上方的值
//所以填表的顺序是从上向下，从左向右的

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 110;
const int M = 5e4 + 10;
int n, h;

int p[N], c[N];
//p[i]表示第i公司买干草包的重量
//c[i]表示需要开销多少元
int f[M];
int main()
{
	cin >> n >> h;
	for(int i = 1; i <= n; i++)
		cin >> p[i] >> c[i];
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= h; j++)
		{
			f[j] = min(f[j], f[max(0, j - p[i])] + c[i]);
		}
	}

	cout << f[h] << endl;
	return 0;
}