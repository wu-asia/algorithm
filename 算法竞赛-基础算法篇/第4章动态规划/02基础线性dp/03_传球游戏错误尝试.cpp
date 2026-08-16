//思路是正确的，但是使用bfs是一种空间和时间成本较高的方法
//无法完全AC代码

#include<iostream>
#include<queue>
#include<utility>

using namespace std;

struct node
{
	int pos, cnt;
};
//node中的cnt是传球第几次，pos是传球的人是谁
int n, m;

int ret;
void bfs()
{
	queue<node> q;
	//初始条件入队，在1处零次操作
	q.push({1, 0});
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		if(t.cnt == m)
		{
			if(t.pos == 1)
				ret++;
			continue;
		}
		//入队
		int left = (t.pos == 1) ? n : t.pos - 1;
		int right = (t.pos == n) ? 1 : t.pos + 1;
		t.cnt++;
		q.push({left, t.cnt});
		q.push({right, t.cnt});
	}

}
int main()
{
	cin >> n >> m;
	bfs();
	cout << ret << endl;
	return 0;
}