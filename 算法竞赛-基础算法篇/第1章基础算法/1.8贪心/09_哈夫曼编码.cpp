#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef long long LL;

priority_queue<LL, vector<LL>, greater<LL>> heap;
int n;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		LL e; cin >> e;
		heap.push(e);
	}
	LL ret = 0;
	while(heap.size() > 1)
	{
		LL x = heap.top();
		heap.pop();
		LL y = heap.top();
		heap.pop();
		ret += x + y;
		heap.push(x + y);
	}
	cout << ret << endl;
	return 0;
}