#include<iostream>
#include<string>

using namespace std;
const int N = 1e3 + 10;
int f[N][N];
//f[i][j]表示的是[i, j]这个区间的字符串变为回文串需要的步骤
int main()
{
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	for(int len = 1; len <= n; len++)//字符串的长度
	{
		for(int i = 1; i + len - 1 <= n; i++)//字符串的左端点
		{
			int j = i + len - 1;
			if(s[i] == s[j])
				f[i][j] = f[i + 1][j - 1];
			else
				f[i][j] = min(f[i + 1][j] + 1, f[i][j - 1] + 1);
		}
	}

	cout << f[1][n] << endl;
	return 0;
}