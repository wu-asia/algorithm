#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int l, n, k;
const int N = 1e7 + 10;

int a[N];
int d[N];

priority_queue<int, vector<int>, less<int>> heap;

int main()
{
	cin >> l >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++)
	{
		d[i] = a[i + 1] - a[i];
		heap.push(d[i]);
	}
	int m = n - 1;
	if(a[1] - 0 != 0)
	{
		m++;
		heap.push(a[1] - 0);
	}
	if(l - a[n])
	{
		m++;
		heap.push(l - a[n]);
	}
	for(int i = 1; i <= k; i++)
	{
		auto t = heap.top();
		heap.pop();
		heap.push(t / 2);
		heap.push(t - t / 2);
	}
	cout << heap.top() << endl;
	return 0;
}