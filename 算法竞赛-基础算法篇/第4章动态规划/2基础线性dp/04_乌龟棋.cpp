#include<iostream>
#include<algorithm>

using namespace std;

const int N = 400, M = 60;
int n, m;
int x[N];
int f[M][M][M][M];
int cnt[5];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	for(int i = 1; i <= m; i++)
	{
		int t;
		cin >> t;
		cnt[t]++;
	}
	f[0][0][0][0] = x[1];
	for(int a = 0; a <= cnt[1]; a++)
	{
		for(int b = 0; b <= cnt[2]; b++)
		{
			for(int c = 0; c <= cnt[3]; c++)
			{
				for(int d = 0; d <= cnt[4]; d++)
				{
					//格子是从 1 开始的必须下标要加上 1
					int i = 1 + a * 1 + b * 2 + c * 3 + d * 4;
					int& t = f[a][b][c][d];
					if(a) t = max(t, f[a - 1][b][c][d] + x[i]);
					if(b) t = max(t, f[a][b - 1][c][d] + x[i]);
					if(c) t = max(t, f[a][b][c - 1][d] + x[i]);
					if(d) t = max(t, f[a][b][c][d - 1] + x[i]);
					//f[a][b][c][d] = t;
				}
			}
		}
	}
	cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
	return 0;
}


// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int N = 45;

// int n, m;
// int x[410];
// int cnt[5];
// int f[N][N][N][N];

// int main()
// {
//     cin >> n >> m;

//     for (int i = 1; i <= n; i++)
//         cin >> x[i];

//     for (int i = 1; i <= m; i++)
//     {
//         int t;
//         cin >> t;
//         cnt[t]++;
//     }

//     for (int a = 0; a <= cnt[1]; a++)
//     for (int b = 0; b <= cnt[2]; b++)
//     for (int c = 0; c <= cnt[3]; c++)
//     for (int d = 0; d <= cnt[4]; d++)
//         f[a][b][c][d] = -1e9;

//     f[0][0][0][0] = x[1];

//     for (int a = 0; a <= cnt[1]; a++)
//     for (int b = 0; b <= cnt[2]; b++)
//     for (int c = 0; c <= cnt[3]; c++)
//     for (int d = 0; d <= cnt[4]; d++)
//     {
//         if (f[a][b][c][d] < 0) continue;

//         int pos = a + 2*b + 3*c + 4*d;

//         if (a < cnt[1])
//             f[a+1][b][c][d] = max(f[a+1][b][c][d],
//                                   f[a][b][c][d] + x[pos + 1]);

//         if (b < cnt[2])
//             f[a][b+1][c][d] = max(f[a][b+1][c][d],
//                                   f[a][b][c][d] + x[pos + 2]);

//         if (c < cnt[3])
//             f[a][b][c+1][d] = max(f[a][b][c+1][d],
//                                   f[a][b][c][d] + x[pos + 3]);

//         if (d < cnt[4])
//             f[a][b][c][d+1] = max(f[a][b][c][d+1],
//                                   f[a][b][c][d] + x[pos + 4]);
//     }

//     cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
// }