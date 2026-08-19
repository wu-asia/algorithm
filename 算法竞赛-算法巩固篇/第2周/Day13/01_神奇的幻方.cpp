#include<iostream>

using namespace std;

const int N = 45;
int a[N][N];

int main()
{
	int n;
	cin >> n;
	int i = 1, j = (n + 1) / 2;
	a[i][j] = 1;
	for(int x = 2; x <= n * n; x++)
	{
		if(i == 1 && j != n)
		{
			i = n, j = j + 1;
			a[i][j] = x;
		}
		else if(i != 1 && j == n)
		{
			i = i - 1, j = 1;
			a[i][j] = x;
		}
		else if(i == 1 && j == n)
		{
			i = i + 1, j = j;
			a[i][j] = x;
		}
		else
		{
			if(a[i - 1][j + 1] == 0)			
			{
				a[i - 1][j + 1] = x;
				i = i - 1, j = j + 1;
			}
			else
			{
				i = i + 1, j = j;
				a[i][j] = x;
			}
		}

	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}