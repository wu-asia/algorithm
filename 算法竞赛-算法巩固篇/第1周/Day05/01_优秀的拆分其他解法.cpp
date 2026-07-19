#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if((n & 1))
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 30; i >= 0; i--)
	{
		if((1 << i) & n)
			cout << (1 << i) << " ";
	}
	cout << endl;
	return 0;
}