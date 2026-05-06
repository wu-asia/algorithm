#include<iostream>
#include<string>

using namespace std;

const int N = 11;
int n;
int a[(1 << N)];
int f[(1 << N)];
string s;

void dfs(int left, int right)
{

	//ret
	if(left > right) return;

	char ret;
	int sum = f[right] - f[left - 1];
	if(sum == 0) ret = 'B';
	else if(sum == right - left + 1) ret = 'I';
	else ret = 'F';

	if(left == right)
	{
		cout << ret;
		return;
	}
	int mid = (left + right) / 2;
	dfs(left, mid);
	dfs(mid + 1, right);

	cout << ret;
}
int main()
{
	cin >> n;
	cin >> s;
	n = (1 << n);
	for(int i = 1; i <= n; i++)
	{
		if(s[i - 1] == '1')
			a[i] = 1;
		else if(s[i - 1] == '0')
			a[i] = 0;
	}
	for(int i = 1; i <= n; i++)
		f[i] = f[i - 1] + a[i];

	dfs(1, n);
	cout << endl;
	return 0;
}