#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;
int t, x, y;
int n = 1e5;
int dist[N];
void bfs()
{
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	while(q.size())
	{
		int t = q.front();
		q.pop();
		int a = t + 1, b = t - 1, c = t * 2;
		if(a <= n && dist[a] == -1)
		{
			dist[a] = dist[t] + 1;
			q.push(a);
		} 
		if(b > 0 && dist[b] == -1)
		{
			dist[b] = dist[t] + 1;
			q.push(b);
		}
		if(c <= n && dist[c] == -1)
		{
			dist[c] = dist[t] + 1;
			q.push(c);
		}
		if(a == y || b == y || c == y)
			return;
	}

}
int main()
{
	cin >> t;
	while(t--)
	{
		memset(dist, -1, sizeof dist);
		cin >> x >> y;
		bfs();
		cout << dist[y] << endl;
	}
	return 0;
}