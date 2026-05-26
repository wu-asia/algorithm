#include<iostream>

using namespace std;
const int N = 5010;
int n;
int a[N], f[N];
//f[i]表示必须以a[i]结尾的最长上升子序列的最大值

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		//初始化f[i]中的值
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
	//ret是f[i]中的最大值
	cout << ret << endl;
	return 0;
}