#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
const int N = 1e4 + 10;
const int M = 1010;
string ts, te;
int n, ti;
int t[N], c[N], p[N];
int f[N][M];
//f[i][j]表示从[1, i]中观看樱花时间不超过j的最大美学值
int time(string ts, string te)
{
	int x, y;
	for(int i = 0; i < ts.size(); i++)
	if(ts[i] == ':')
		x = i;
	for(int i = 0; i < te.size(); i++)
		if(te[i] == ':')
			y = i;
	int h1 = 0, h2 = 0, m1 = 0, m2 = 0;

	for(int i = 0; i < x; i++)
		h1 = h1 * 10 + (ts[i] - '0');
	for(int i = 0; i < y; i++)
		h2 = h2 * 10 + (te[i] - '0');
	for(int i = x + 1; i < ts.size(); i++)
		m1 = m1 * 10 + (ts[i] - '0');
	for(int i = y + 1; i < te.size(); i++)
		m2 = m2 * 10 + (te[i] - '0');
	int t = (h2 - h1) * 60 + (m2 - m1);
	return t;
}
int main()
{
	cin >> ts >> te >> n;
	ti = time(ts, te);
	for(int i = 1; i <= n; i++)
	{
		cin >> t[i] >> c[i] >> p[i];
	}
	//t表示时间，c表示美学值，p表示次数

	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= ti; j++)
		{
			f[i][j] = f[i - 1][j];
			if(j < t[i]) continue;
			if(p[i] == 0)
				f[i][j] = max(f[i][j], f[i][j - t[i]] + c[i]);
			else if(p[i] == 1)
				f[i][j] = max(f[i][j], f[i - 1][j - t[i]] + c[i]);
			else
				for(int k = 1; k <= p[i] && j >= k * t[i]; k++)
					f[i][j] = max(f[i][j], f[i - 1][j - k * t[i]] + k * c[i]);
		}
	}

	cout << f[n][ti] << endl;
	return 0;
}