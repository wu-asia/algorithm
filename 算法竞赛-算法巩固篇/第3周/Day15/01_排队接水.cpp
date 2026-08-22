#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1e3 + 10;
int n;
struct node
{
	int id, t;
}a[N];
bool cmp(node& x, node& y)
{
	return ((x.t < y.t) || (x.t == y.t && x.id < y.id));
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].t;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n, cmp);
	double cnt = 0.0;
	for(int i = 1; i <= n; i++)
	{
		cout << a[i].id << " ";
		cnt += (n - i) * a[i].t;
	}
	cout << endl;
	printf("%.2f\n", cnt / n);
	return 0;
}