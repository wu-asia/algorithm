#include<iostream> 

using namespace std;

int n;
const int N = 300;
int a[N];
int f[N][N];

int main()
{
	cin >> n;
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i][i] = a[i];
		ret = max(ret, a[i]);
	}

	for(int len = 2; len <= n; len++)
	{
		for(int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			for(int k = i; k < j; k++)
			{
				if(f[i][k] && f[i][k] == f[k + 1][j])
				{
					f[i][j] = max(f[i][j], f[i][k] + 1);
				}
			}
			ret = max(ret, f[i][j]);
		}
	}
	cout << ret << endl;
	return 0;
}