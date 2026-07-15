#include<iostream>
#include<string>

using namespace std;

int n;
string s;
int main()
{
	cin >> n;
	cin >> s;
	if(n % 2 == 0)
	{
		for(int i = 0; i < n; i++)
		{
			cout << s[i];
			if(i % 2 && i != n - 1) cout << "-";
		}
		cout << endl;
	}
	else
	{
		for(int i = 0; i < 3; i++)
			cout << s[i];
		cout << "-";
		for(int i = 3; i < n; i++)
		{
			cout << s[i];
			if(i % 2 == 0 && i != n - 1) cout << "-";
		}
		cout << endl;
	}
	return 0;
}