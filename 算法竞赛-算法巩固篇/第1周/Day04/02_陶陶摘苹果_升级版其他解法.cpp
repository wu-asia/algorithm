#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5e3 + 10;
int n, s;
int a, b;
int t[N];
int cnt;
int main()
{
	cin >> n >> s;
	cin >> a >> b;
	a += b;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		if(x > a) continue;
		t[++cnt] = y;
	}
	sort(t + 1, t + cnt + 1);
	int ret = 0, sum = 0;
	for(int i = 1; i <= cnt; i++)
	{
		sum += t[i];
		if(sum < s)
			ret++;
		else break;
	}
	cout << ret << endl;
	return 0;
}