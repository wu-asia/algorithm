#include<iostream>

using namespace std;

const int N = 1e4 + 10;
char f[N][N];
int T, p, x, y;
char dfs(int x, int y)
{
	if(f[x][y]) return f[x][y];
	f[x][y] = '3';
	if(x == 0) return '1';
	if(y == 0) return '2';
	f[x][y] = dfs((x + y) % p, (x + 2 * y) % p);
	return f[x][y];
}
int main()
{
	cin >> T >> p;
	while(T--)
	{
		cin >> x >> y;
		char flag = dfs(x, y);
		if(flag == '1') cout << '1' << endl;
		else if(flag == '2') cout << '2' << endl;
		else cout << "error" << endl;
	}
	return 0;
}