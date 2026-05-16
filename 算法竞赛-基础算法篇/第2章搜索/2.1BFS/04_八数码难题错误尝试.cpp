#include<iostream>
#include<utility>
#include<string>
using namespace std;

const int N = 15;
int a[N][N];
int pos[N][N] = {
	{1, 2, 3}, 
	{8, 0, 4},
	{7, 6, 5}
};

int x, y;
int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			a[i][j] = s[i * j + j];
			if(a[i][j] == 0)
			{
				x = i;
				y = j;
			}
		}
	}

	return 0;
}