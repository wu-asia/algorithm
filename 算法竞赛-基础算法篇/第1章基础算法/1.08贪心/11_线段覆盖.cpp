#include<iostream>
#include<algorithm>

#include<unordered_set>

using namespace std;

const int N = 1e6 + 10;
int n;

struct node
{
	int l, r;
}a[N];

bool cmp(node& x, node& y)
{
	return x.l < y.l;
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].l >> a[i].r;
	}

	sort(a + 1, a + n + 1, cmp);

	int ret = 1;
	int r = a[1].r;
	for(int i = 2; i <= n; i++)
	{
		int left = a[i].l, right = a[i].r;
		if(r > left)
		{
			r = min(r, right);
		}
		else
		{
			ret++;
			r = right;
		}
	}
	cout << ret << endl;
	return 0;
}