//错误原因：石子合并需要相邻两个元素
//而使用哈夫曼编码是可以随机的
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 310;
int n;
int m[N];
priority_queue<int, vector<int>, greater<int>> heap;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> m[i];
		heap.push(m[i]);
	}
	int ret = 0;
	while(heap.size() > 1)
	{
		int a = heap.top();
		heap.pop();
		int b = heap.top();
		heap.pop();
		ret += a + b;
		heap.push(a + b);
	}
	cout << ret << endl;
	return 0;
}