#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

const int N = 1e4 + 10;
int n, m;

priority_queue<int, vector<int>, greater<int>> heap;
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		heap.push(0);
	}

	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		int t = heap.top(); 
		heap.pop();
		t += x;
		heap.push(t);
		ret = max(t, ret);
	}
	cout << ret << endl;
	return 0;
}