#include<iostream>
using namespace std;

int n, k;
const int N = 5e6 + 10;
long long a[N];
long long ret;
long long path;
void dfs(int pos, int begin)
{
	if(pos > n)
	{
		is_prime(path);
		return;
	}
	for(int i = begin; i <= n)

}
int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 1);
	return 0;
}