#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int n, c;
int t[N];
int main()
{
	cin >> n >> c;
	for(int i = 1; i <= n; i++)
		cin >> t[i];
	int pret = t[1], ret = 1;
	for(int i = 2; i <= n; i++)
	{
		if(t[i] - pret <= c)
		{
			ret++;
			pret = t[i];
		}
		else
		{
			ret = 1;
			pret = t[i];
		}
	}
	cout << ret << endl;
	return 0;
}