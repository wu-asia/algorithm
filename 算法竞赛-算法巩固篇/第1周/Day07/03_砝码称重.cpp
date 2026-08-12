#include<iostream>

using namespace std;

const int N = 25;
const int M = 1e3 + 10;
int w[] = {0, 1, 2, 3, 5, 10, 20};
int a[N];
int n = 6, m = 1000;
bool f[M];

int main()
{
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	f[0] = true;
	for(int i = 1; i <= n; i++)
	{
		for(int j = m; j >= 0; j--)
		{
			for(int k = 0; k <= a[i] && k * w[i] <= j; k++)
				if(f[j - k * w[i]])
					f[j] = true;
		}
	}
	int ret = 0;
	for(int j = 1; j <= m; j++)
		if(f[j])
			ret++;
	cout << "Total=" << ret << endl;
	return 0;
}