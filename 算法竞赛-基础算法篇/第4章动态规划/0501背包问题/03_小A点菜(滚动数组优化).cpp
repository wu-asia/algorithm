#include<iostream>
#include<cstring>

using namespace std;
const int N = 1e3 + 10;

int n, m;
int a[N];
int f[N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	//memset(f, -0x3f, sizeof f);
	f[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = m; j >= 1; j--)
		{
			if(j >= a[i])
				f[j] += f[j - a[i]];
		}
	}

	cout << f[m] << endl;
	return 0;
}