#include<iostream>

using namespace std;

int a[20];
int main()
{
	for(int i = 1; i <= 10; i++)
		cin >> a[i];
	int x; cin >> x;
	int cnt = 0;
	for(int i = 1; i <= 10; i++)
		if(x + 30 >= a[i])
			cnt++;
	cout << cnt << endl;
	return 0;
}