#include<iostream>

using namespace std;

typedef long long LL;
int n;
const int N = 1e5 + 10;
LL s[N];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	LL ret = 0;
	//cout << n << endl;
	for(int i = 1; i <= n; i++)
	{
		//cout << "r" << endl;
		for(int j = i; j <= n; j++)
		{
			LL t = s[j] - s[i - 1];
			LL d = j - i + 1;
			if(2 * t == d)
				ret = max(ret, d);
		}
	}
	cout << ret << endl;
	return 0;
}