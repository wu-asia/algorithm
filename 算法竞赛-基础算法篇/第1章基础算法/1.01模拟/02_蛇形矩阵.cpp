#include<iostream>
using namespace std;
const int N = 10;
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, -1, 0};
int arr[N][N];
int main()
{
	int n;
	cin >> n;
	int pos = 0;
	int x = 0, y = 0;
	for(int i = 1; i <= n * n; i++)
	{
		arr[x][y] = i;
		int a = x + dx[pos], b = y + dy[pos];
		if(a < 1 || a > n || b < 1 || b > n || arr[a][b])
		{
			pos = (pos + 1) % 4;
			a = x + dx[pos];
			b = y + dy[pos];
		}
		
	}
	return 0;
}