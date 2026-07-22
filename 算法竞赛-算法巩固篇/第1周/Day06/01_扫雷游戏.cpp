#include<iostream>

using namespace std;

const int N = 110;
int n, m;
char ch[N][N];

int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> ch[i];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(ch[i][j] == '?') ch[i][j] = '0';

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(ch[i][j] == '*')
			{
				for(int k = 0; k < 8; k++)
				{
					int x = i + dx[k], y = j + dy[k];
					if(x < 0 || x >= n || y < 0 || y >= m || ch[x][y] == '*')
						continue;
					ch[x][y] = (ch[x][y] - '0') + 1 + '0';
				}
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout << ch[i][j];
		cout << endl;
	}
	return 0;
}