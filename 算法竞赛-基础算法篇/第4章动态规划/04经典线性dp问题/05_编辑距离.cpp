#include<iostream>
#include<string>

using namespace std;
const int N = 2e3 + 10;
string a, b;
int f[N][N];
//f[i][j]表示的是a字符串以i为结尾和b字符串以j为结尾，需要操作的最小次数
//才能形成一个相同的字符串
//f[0][j]表示a为空串时(即a = "")，有j位字符的b需要操作多少次与a相同
//对b进行删除操作，删除j次(即f[0][j] = j)
//f[i][0]表示b为空串时(即b = "")，有0位字符的b需要操作多少次与a相同
//对a进行插入操作，插入i次(即f[i][0] = i)

int main()
{
	cin >> a >> b;
	int n = a.size(), m = b.size();
	a = " " + a, b = " " + b;
	for(int i = 1; i <= n; i++)
		f[i][0] = i;
	for(int j = 1; j <= m; j++)
		f[0][j] = j;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			//当a字符串的i位置与b的j位置相同时
			//无需对字符串进行操作
			if(a[i] == b[j])
				f[i][j] = f[i - 1][j - 1];
			else
				f[i][j] = min(min(f[i][j - 1] + 1, f[i - 1][j] + 1), f[i - 1][j - 1] + 1);
		}
	}
	cout << f[n][m] << endl;
	return 0;
}