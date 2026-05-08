#include<iostream>

using namespace std;
int n, k;
int ret;
int path;
void dfs(int pos, int begin)
{
	//剪枝
	if(pos == k)
	{
		if(path == n) ret++;
		return;
	}
	// //可行性剪枝
	// //(在函数内部进行可行性剪枝是需要进入dfs函数的，消耗时间)
	// if(path + begin * (k - pos) > n) return;
	for(int i = begin; i <= n; i++)
	{
		//可行性剪枝
		if(path + i * (k - pos) > n)
			return;
		path += i;
		dfs(pos + 1, i);
		path -= i;
	}

}
int main()
{
	cin >> n >> k;
	dfs(0, 1);
	cout << ret << endl;
	return 0;
}