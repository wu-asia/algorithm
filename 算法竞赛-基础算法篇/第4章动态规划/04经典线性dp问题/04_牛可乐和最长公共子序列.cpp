#include<iostream>
#include<string>

using namespace std;
typedef long long LL;
const int N = 5e3 + 10;
string s, t;
LL f[N][N];
//f[i][j]表示的是s的第i位和t的第j位的最长共有子序列的长度

int main()
{
	while(cin >> s >> t)
	{
		int n = s.size(), m = t.size();
		s = " " + s, t = " " + t;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(s[i] == t[j])
					f[i][j] = f[i - 1][j - 1] + 1;
				else
					f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
		cout << f[n][m] << endl;
	}
	return 0;
}