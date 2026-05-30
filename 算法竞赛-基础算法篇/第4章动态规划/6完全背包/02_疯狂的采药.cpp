// #include<iostream>

// using namespace std;
// const int N = 1e4 + 10;
// int t, m;
// int a[N], b[N];
// //a[i]表示时间，b[i]表示价值
// int f[N][N];
// //f[i][j]表示的是从[1, i]中挑选出药材，时间不超过j，所采到药材的最大价值
// int main()
// {
// 	cin >> t >> m;
// 	for(int i = 1; i <= m; i++)
// 		cin >> a[i] >> b[i];
// 	for(int i = 1; i <= m; i++)
// 	{
// 		for(int j = 0; j <= t; j++)
// 		{
// 			f[i][j] = f[i - 1][j];
// 			if(j >= a[i])
// 				f[i][j] = max(f[i][j], f[i][j - a[i]] + b[i]);
// 		}
// 	}
// 	// for(int i = 1; i <= m; i++)
// 	// {
// 	// 	for(int j = 1; j <= t; j++)
// 	// 	{
// 	// 		cout << f[i][j] << " ";
// 	// 	}
// 	// 	cout << endl;
// 	// }
// 	cout << f[m][t] << endl;
// 	return 0;
// }



#include<iostream>

using namespace std;
const int N = 1e7 + 10;
typedef long long LL;
LL t, m;
LL a[N], b[N];
//a[i]表示时间，b[i]表示价值
LL f[N];
//f[i][j]表示的是从[1, i]中挑选出药材，时间不超过j，所采到药材的最大价值
int main()
{
	cin >> t >> m;
	for(int i = 1; i <= m; i++)
		cin >> a[i] >> b[i];
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j <= t; j++)
		{
			if(j >= a[i])
				f[j] = max(f[j], f[j - a[i]] + b[i]);
		}
	}
	// for(int i = 1; i <= m; i++)
	// {
	// 	for(int j = 1; j <= t; j++)
	// 	{
	// 		cout << f[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << f[t] << endl;
	return 0;
}