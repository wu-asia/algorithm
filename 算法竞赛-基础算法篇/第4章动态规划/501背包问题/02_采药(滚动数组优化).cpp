#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10010;
int t, m;
int ti[N], w[N];
int f[N];

int main()
{
	cin >> t >> m;
	for(int i = 1; i <= m; i++)
		cin >> ti[i] >> w[i];
	for(int i = 1; i <= m; i++)
	{
		for(int j = t; j >= ti[i]; j--)
		{
			if(j >= ti[i])
				f[j] = max(f[j], f[j - ti[i]] + w[i]);
		}
	}

	cout << f[t] << endl;
	return 0;
}