#include<iostream>
#include<queue>
#include<set>

using namespace std;

priority_queue<int, vector<int>, greater<int>> heap;
int main()
{
	int n;
	cin >> n;
	set<int> s;
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		s.insert(x);
	}
	if(s.size() < 2){ cout << -1 << endl;
return 0;}
	for(int i = 1; i <= 3; i++)
	{
		heap.push(0);
	}
	for(auto& e : s)
	{
		auto t = heap.top();
		if(t < e)
		{
			heap.pop();
			heap.push(e);
		}
	}
	cout << heap.top() << endl;
	return 0;
}