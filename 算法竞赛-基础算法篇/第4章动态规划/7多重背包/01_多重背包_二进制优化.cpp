//多重背包在使用二进制优化的时候
//是可以将时间复杂度优化: O(n*m*x) -> O(n*m*logx)
//但是求方案数的时候，是不能使用二进制优化的

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110 * 5;
int n, m;
int w[N], v[N], pos;
int f[N];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		//按照二进制拆分
		int t = 1;
		while(x >= t)
		{
			pos++;
			w[pos] = t * y;
			v[pos] = t * z;
			x -= t;
			t *= 2;
		}
		if(x) //处理剩余
		{
			pos++;
			w[pos] = x * y;
			v[pos] = x * z;
		}
	}
	//针对拆分之后的物品，做一次01背包即可
	for(int i = 1; i <= pos; i++)
		for(int j = m; j >= w[i]; j--)
			f[j] = max(f[j], f[j - w[i]] + v[i]);
	cout << f[m] << endl;
	return 0;
}