#include<iostream>
#include<algorithm>

using namespace std;
const int N = 5010;
int a[N], f[N];
//f[i]表示的是以i结尾的最长上升子序列的长度
//必须是以a[i]结尾的子序列
int n;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		//初始化f[i]出的值，一定是一
		f[i] = 1;
		for(int j = 1; j < i; j++)
		{
			if(a[j] < a[i])
			{
				f[i] = max(f[i], f[j] + 1);
			}
		}
		ret = max(ret, f[i]);
	}
	return 0;
}