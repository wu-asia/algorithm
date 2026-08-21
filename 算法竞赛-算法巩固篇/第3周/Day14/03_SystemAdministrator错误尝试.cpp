#include<iostream>

using namespace std;

int n, m, v;

int main()
{
	cin >> n >> m >> v;
	if(m > n * (n - 1) - 4)
	{
		cout << -1 << endl;
	}
	else
	{
		int d = (n - 1) * 2;
		if(d >= m)
		{
			if(m % 2)
			{
				cout << 1 << " " << v << endl;
				//奇数
				for(int i = 2; i <= (m - 1) / 2; i++)
				{
					cout << i << " " << v << endl;
					cout << v << " " << i << endl;
				}
			}	
			else
			{
				for(int i = 1; i <= m / 2; i++)
				{
					cout << i << " " << v << endl;
					cout << v << " " << i << endl;
				}
			}

		}
		else
		{
			for(int i = 1; i <= n; i++)
			{
				if(i == v) continue;
				cout << i << " " << v << endl;
				cout << v << " " << i << endl;
			}
			int a = m - d;
			if(a % 2)
			{
				//a 为奇数

			}
			else
			{
				for(int i = 0; i <= a; i += 2)
			}
		}
	}
	return 0;
}



#include<iostream>


using namespace std;

int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	if(m > n * (n - 1) - 4)
	{
		cout << -1 << endl;
	}
	else
	{

		}
	}
	return 0;
}