#include<iostream>
#include<iostream>

using namespace std;

typedef long long LL;
const int N = 30;
LL f[N][N][N];
LL w(LL a, LL b, LL c)
{
	if(f[a][b][c] != -1) return f[a][b][c];
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	else if(a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	else if(a < b && b < c)
		{f[a][b][c] = f[a][b][c - 1] + f[a][b - 1][c - 1] - f[a][b - 1][c];
				return f[a][b][c];}
	else
		{f[a][b][c] = f[a - 1][b][c] + f[a - 1][b - 1][c] + f[a - 1][b][c - 1] - f[a - 1][b - 1][c - 1];
				return f[a][b][c];}
}
int main()
{
	int a, b, c;
	while(1)
	{
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				for(int k = 0; k < N; k++)
					f[i][j][k] = -1;
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
	}

	return 0;
}