#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5e3 + 10;
int n, m;
//n表示牛奶的总量，m提供牛奶农民的个数
struct node
{
	int p, a;
}s[N];

bool cmp(node& x, node& y)
{
	return x.p < y.p;
}
//p[i]单价，a[i]最多牛奶数
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> s[i].p >> s[i].a;
	sort(s + 1, s + 1 + m, cmp);
	int sum = 0;
	int ret = 0;
	for(int i = 1; i <= m; i++)
	{
		sum += s[i].a;
		ret += s[i].p * s[i].a;
		if(sum > n)
		{
			int d = sum - n;
			int x = s[i].a - d;
			ret = ret - s[i].a * s[i].p + x * s[i].p;
			break;
		}
	}
	cout << ret << endl;
	return 0;
}