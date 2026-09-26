//埃筛的时间复杂度是O(n log log n)
#include<iostream>

using namespace std;

const int N = 1e4 + 10;

//标记数组
int st[N];
//储存素数
int prime[N];
//cnt表示素数个数
//n表示要筛选的范围
int cnt, n;

int main()
{
	cin >> n;
	//埃筛
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])
		{
			prime[++cnt] = i;
			for(int j = i * i; j <= n; j += i)
			{
				st[j] = true;
			}
		}
	}

	for(int i = 1; i <= cnt; i++)
		cout << prime[i] << " ";
	cout << endl;
	return 0;
}