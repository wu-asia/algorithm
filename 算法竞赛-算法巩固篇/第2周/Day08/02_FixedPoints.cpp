#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], f[N];
bool st[N];
int main()
{
	int n;
	cin >> n;
	int p = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] == i)
			p++;
		else
		{
			f[a[i]] = i;
			st[i] = true;
		}
	}
	if(p == n)
	{
		cout << p << endl;
		cout << "h" << endl;
		return 0;
	}
	bool flag = false;
	for(int i = 0; i < n; i++)
	{
		if(st[i])
		{
			if(f[a[i]] == f[i])
			{
				cout << a[i] << " " << i << endl;
				p += 2;
				flag = true;
				cout << "tow" << endl;
				break;
			}

		}
	}
	if(!flag) p++;
	cout << p << endl; 
	return 0;
}