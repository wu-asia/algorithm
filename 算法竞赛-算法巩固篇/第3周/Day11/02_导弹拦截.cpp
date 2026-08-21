#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;
struct node
{
	int x, y, d;
}a[N];

int calc(int i, int x, int y)
{
	int dx = (x - a[i].x) * (x - a[i].x);
	int dy = (y - a[i].y) * (y - a[i].y);
	return dx + dy;
}

bool cmp(node& a, node& b)
{
	return a.d > b.d;
}
int main()
{
	int n;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].d = calc(i, x1, y1);
	}
	sort(a + 1, a + n + 1, cmp);

	int ret = a[1].d + 0;
	int r2 = 0;
	for(int i = 2; i <= n + 1; i++)
	{
		int r1 = a[i].d;
		r2 = max(r2, calc(i - 1, x2, y2));
		ret = min(ret, r2 + r1);
	}
	cout << ret << endl;
	return 0;
}