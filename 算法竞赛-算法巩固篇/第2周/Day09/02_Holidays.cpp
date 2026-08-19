#include<iostream> 

using namespace std;

const int N = 110;
int f[N];
int a, b;
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		f[a] += 1;
		f[b + 1] -= 1;
	}
	for(int i = 1; i <= n; i++)
	{
		f[i] += f[i - 1];
	}
	for(int i = 1; i <= n; i++)
	{
		if(f[i] != 1)
		{
			cout << i << " " << f[i] << endl;
			return 0;
		}
	}
	cout << "OK" << endl;
	return 0;
}
