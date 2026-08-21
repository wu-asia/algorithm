#include<iostream>

using namespace std;

int a, b, n;
const int N = 5e5 + 10;
int w[N];

bool check(int x)
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		
		if(w[i] <= a * x)
			continue;
		int d = w[i] - a * x;
		cnt += ((d / b) + (d % b == 0 ? 0 : 1));
	}
	return (cnt <= x);
}
int main()
{
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++)
		cin >> w[i];

	int left = 1, right = 5e5;
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(check(mid)) right = mid;
		else left = mid + 1;
	}
	cout << left << endl;
	return 0;
}