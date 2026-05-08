#include<iostream>
#include<cstring>

using namespace std;

int f[35];
int n;
int dfs(int n)
{
	if(f[n] != -1) return f[n];
	if(n == 0) return 0;
	if(n == 1 || n == 2) return 1;
	f[n] = dfs(n - 1) + dfs(n - 2);
	return f[n];
}
int main()
{
	memset(f, -1, sizeof f);
	cin >> n;
	cout << dfs(n) << endl;
	return 0;
}