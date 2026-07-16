#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5e3 + 10;
int x[N], y[N];
int a, b;
//椅子高度a，陶陶高度b
int n, s;
//n苹果数量，s力气
int f[N];
bool st[N];

int main()
{
	cin >> n >> s;
	cin >> a >> b;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		if(x[i] > a + b)
			st[i] = true;
	}

	for(int i = 1; i <= n; i++)
	{
		if(st[i]) continue;
		for(int j = s; j >= 1; j--)
		{
			if(j - y[i] > 0)
				f[j] = max(f[j], f[j - y[i]] + 1);
		}
	}
	cout << f[s] << endl;
	return 0;
}