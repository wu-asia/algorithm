#include<iostream>

using namespace std;

const int N = 35;
const int M = 3e4 + 10;
int n, m;
//n表示钱的总数，m表示购买的个数
int v[N], p[N];
//v价格，p重要度
int f[M];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> v[i] >> p[i];

	for(int i = 1; i <= m; i++)
	{
		for(int j = n; j >= 1; j--)
		{
			if(j >= v[i])
				f[j] = max(f[j], f[j - v[i]] + v[i] * p[i]);
		}
	}
	cout << f[n] << endl;
	return 0;
}