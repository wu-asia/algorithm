#include<iostream>
using  namespace std;


int n;
char a, b, c;

void dfs(int n, int x, int y, int z)
{
	if(n == 0) return;
	dfs(n - 1, x, y, z);
	printf("%c->%d->%c\n", x, n, z);
	dfs(n - 1, y, x, z);
}
int main()
{
	cin >> n >> a >> b >> c;
	dfs(n, a, b, c);
	return 0;
}