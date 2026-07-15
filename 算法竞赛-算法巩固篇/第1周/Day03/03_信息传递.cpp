#include<iostream>
#include<queue>

using namespace std;
const int N = 2e5 + 10;

int ne[N];
int in[N];
bool st[N];
int cnt;
int n;
void dfs(int x)
{
	cnt++;
	st[x] = true;
	if(!st[ne[x]]) dfs(ne[x]);
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> ne[i];
		//i -> ne[i];
		in[ne[i]]++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(in[i] == 0)
			q.push(i);
	}
	while(q.size())
	{
		auto a = q.front();
		q.pop();
		st[a] = true;
		int b = ne[a];
		in[b]--;
		if(in[b] == 0) q.push(b);
	}

	//dfs
	int ret = n;
	for(int i = 1; i <= n; i++)
	{
		if(st[i]) continue;
		cnt = 0;
		dfs(i);
		ret = min(ret, cnt);
	}
	cout << ret << endl;
	return 0;
}