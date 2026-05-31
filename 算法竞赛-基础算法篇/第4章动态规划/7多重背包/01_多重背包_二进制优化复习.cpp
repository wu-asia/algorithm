//所有的数字在转化为二进制的时候每一位上的数字只能是0, 1
//所以可以将多重背包问题转换为01背包问题

#include<iostream>
#include<algorithm>

using namespace std;
const int N = 110 * 5;
int n, m;
int w[N], v[N];
int pos;
int f[N];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		//x表示的是每一种物品的个数
		//y表示物体的重量，z表示物体的价值
		//可以使用二进制将其拆解为不同的数字储存
		int t = 1;
		while(x >= t)
		{
			pos++;
			w[pos] = t * y;
			v[pos] = t * z;
			x -= t;
			t *= 2;
		}
		if(x)//处理剩余情况
		{
			pos++;
			w[pos] = x * y;
			v[pos] = x * z;
		}
	}
	//使用01背包解决问题
	for(int i = 1; i <= pos//所有的数字在转化为二进制的时候每一位上的数字只能是0, 1
//所以可以将多重背包问题转换为01背包问题

#include<iostream>
#include<algorithm>

using namespace std;
const int N = 110 * 5;
int n, m;
int w[N], v[N];
int pos;
int f[N];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		//x表示的是每一种物品的个数
		//y表示物体的重量，z表示物体的价值
		//可以使用二进制将其拆解为不同的数字储存
		int t = 1;
		while(x >= t)
		{
			pos++;
			w[pos] = t * y;
			v[pos] = t * z;
			x -= t;
			t *= 2;
		}
		if(x)//处理剩余情况
		{
			pos++;
			w[pos] = x * y;
			v[pos] = x * z;
		}
	}
	//使用01背包解决问题
	for(int i = 1; i <= n; i++)
		for(int j = m; j >= w[i]; j--)
			f[j] = max(f[j], f[j - w[i]] + v[i]);
	cout << f[m] << endl;
	return 0;
}; i++)
		for(int j = m; j >= w[i]; j--)
			f[j] = max(f[j], f[j - w[i]] + v[i]);
	cout << f[m] << endl;
	return 0;
}