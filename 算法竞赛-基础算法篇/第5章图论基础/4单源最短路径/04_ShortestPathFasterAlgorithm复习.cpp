#include<iostream>
#include<queue>
#include<vector>
#include<utility>

using namespace std;
const int N = 1e4 + 10, INF = 2147483647;
typedef pair<int, int> PII;

int n, m, s;
vector<PII> edges[N];

int dist[N];
bool st[N];

void sfpa()
{
	for(int i = 0; i <= n; i++)
		dist[i] = INF;

	dist[s] = 0;
	queue<int> q;
	//进入队列
	q.push(s);
	//标记顶点
	st[s] = true;

	while(q.size())
	{
		int a = q.front();
		q.pop();
		st[a] = false;

		for(auto& e : edges[a])
		{
			int b = e.first, c = e.second;
			if(dist[a] != INF && dist[a] + c < dist[b])
			{
				dist[b] = dist[a] + c;
				if(!st[b])
				{
					q.push(b);
					st[b] = true;
				}
			}

		}
	}
	for(int i = 1; i <= n; i++)
		cout << dist[i] << " ";
	cout << endl;
}

int main()
{
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({b, c});
	}
	sfpa();
	return 0;
}