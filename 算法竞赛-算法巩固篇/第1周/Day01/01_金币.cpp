#include<iostream>

using namespace std;

int k;
int main()
{
	cin >> k;
	int i = 0;
	while(i * (i + 1) <= 2 * k)
		i++;
	i--;
	if(i * (i + 1) == 2 * k)
		cout << i * (i + 1) * (2 * i + 1) / 6 << endl;
	else
	{
		int d = k - i * (i + 1) / 2;
		cout << d * (i + 1) + i * (i + 1) * (2 * i + 1) / 6 << endl;
	}
	return 0;
}