#include<iostream>

using namespace std;

int l, n, k;

const int N = 1000010;

int d[N];

bool check(int x)
{
	int cnt = 0;
	for(int i = 2; i <= n; i++)
	{
		int diff = d[i] - d[i - 1];
		cnt += ((diff / x) - (diff % x == 0 ? 1 : 0));
	}
	return (cnt <= k);
}
int main()
{
	cin >> l >> n >> k;

	for(int i = 1; i <= n; i++)
		cin >> d[i];

	int left = 1, right = 1e7;
	//mid 表示空旷指数
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(check(mid)) right = mid;
		else left = mid + 1;
	}
	cout << left << endl;
	return 0;
}