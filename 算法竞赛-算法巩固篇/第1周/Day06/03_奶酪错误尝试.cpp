#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int N = 1e3 + 10;
typedef long long LL;

LL t;
LL n, h, r;


struct node
{
	LL x, y, z;
}a[N];

bool cmp(node& k, node& m)
{
	return k.z < m.z;
}

bool func()
{
	if(a[1].z > r) return false;
	if(a[n].z + r < h) return false;
	for(int i = 1; i < n; i++)
	{
		LL x1 = a[i].x, y1 = a[i].y, z1 = a[i].z;
		LL x2 = a[i + 1].x, y2 = a[i + 1].y, z2 = a[i + 1].z;
		LL dd = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
		double dist = sqrt(dd);
		if(dist > 2 * r) return false;
	}
	return true;
}

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> h >> r;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		sort(a + 1, a + 1 + n, cmp);
		if(func())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}