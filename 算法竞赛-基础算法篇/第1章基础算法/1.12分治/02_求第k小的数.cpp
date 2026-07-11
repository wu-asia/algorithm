#include<iostream>
#include<queue>

using namespace std;

int n, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	priority_queue<int, vector<int>, less<int>> heap;
	cin >> n >> k;
	for(int i = 0; i <= k; i++)
	{
		int x; cin >> x;
		heap.push(x);
	}
	for(int i = 1; i <= n - k - 1; i++)
	{
		int x; cin >> x;
		int t = heap.top();
		if(x > t) continue;
		else
		{
			heap.pop();
			heap.push(x);
		}
	}
	cout << heap.top() << endl;
	return 0;
}