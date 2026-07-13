#include<iostream>

using namespace std;
typedef long long LL;
int n, m;
int main()
{
	LL square = 0, rectangle = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				for(int l = 1; l <= m; l++)
				{
					int length = l - j;
					int width = k - i;
					if(length < 0 || width < 0) continue;
					else
					{
						if(length == width) square++;
						else rectangle++;
					}
				}
			}
		}
	}

	cout << square << " " << rectangle << endl;
	return 0;
}