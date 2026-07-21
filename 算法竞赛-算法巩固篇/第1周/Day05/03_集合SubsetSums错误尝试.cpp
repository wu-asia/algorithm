#include<iostream>

using namespace std;
int n, sum;
int ret;
int s;
void dfs(int x)
{
	if(x > n) return;

	//选
	s += x;
	cout << s << endl;
	if(s == sum / 2)
		ret++;
	dfs(x + 1);
	s -= x;
	//不选
	dfs(x + 1);
}
int main()
{
	cin >> n;
	sum = (1 + n) * n / 2;
	//cout << sum << endl;
	dfs(1);
	cout << ret / 2 << endl;
}