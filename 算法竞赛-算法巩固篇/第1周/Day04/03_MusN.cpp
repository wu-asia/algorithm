#include<iostream>

using namespace std;

int n, q;
const int N = 5e3 + 10;	
int f[N];
int main()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		f[i] = f[i - 1] + x;
	}

	while(q--)
	{
		int y;
		cin >> y;
		int l = 1, r = n;
		while(l < r)
		{
			int mid = (l + r) / 2;
			if(f[mid] > y) r = mid;
			else l = mid + 1;
		}
		cout << l << endl;
	}
	return 0;
}