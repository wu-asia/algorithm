#include<iostream>

using namespace std;


int dfs(int n, int i, int j, int begin)
{
	if(i == 1) return (begin + j - 1);
	else if(j == n) return (begin + (n - 1) + i - 1);
	else if(i == n) return (begin + 2 * (n - 1) + (n - j));
	else if(j == 1) return (begin + 3 * (n - 1) + (n - i));
	return dfs(n - 2, i - 1, j - 1, begin + 4 * (n - 1));
}

int main()
{
	int n;

	int i, j;
	cin >> n >> i >> j;
	cout << dfs(n, i, j, 1) << endl;
	return 0;
}