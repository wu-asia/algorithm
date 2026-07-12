#include<iostream>
#include<ctime>
#include<algorithm>

using namespace std;
const int N = 5e6 + 10;
int n, k;
int a[N];

int get_random(int left, int right)
{
	return a[rand() % (right - left + 1)  + left];
}

int quick_select(int left, int right, int k)
{
	if(left >= right) return a[left];
	int p = get_random(left, right);
	int l = left - 1, r = right + 1, i = left;
	while(i < r)
	{
		if(a[i] < p) swap(a[++l], a[i++]);
		else if(a[i] == p) i++;
		else swap(a[--r], a[i]);
	}
	int x = l - left + 1, y = r - 1 - l, z = right - r + 1;
	if(k <= x)
	{
		return quick_select(left, l, k);
	}
	else if(k <= x + y)
	{
		return p;
	}
	else
	{
		return quick_select(r, right, k - x - y);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	srand(time(NULL));
	cin >> n >> k;
	k++;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	cout << quick_select(1, n, k) << endl;
	return 0;
}