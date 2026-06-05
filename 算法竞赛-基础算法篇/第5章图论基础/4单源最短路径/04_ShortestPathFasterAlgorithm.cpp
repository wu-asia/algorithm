//shortest path faster algorithm在通常情况下的时间复杂度是O(km)
//k是一个较小的常数，m是边的个数
//但是在差的时间复杂度是O(nm)
//n是顶点个数，m是边的个数
#include<iostream>
#include<queue>
#include<vector>
#include<utility>

using namespace std;
typedef pair<int, int> PII;
const int N = 1e4 + 10, INF = 2147483647;

vector<PII> edges[N];
int n , m, s;

int dist[N];
bool st[N];
void spfa()
{
	for(int i = 0; i <= n; i++)
		dist[i] = INF;
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	st[s] = true;

	while(q.size())
	{
		auto a = q.front();
		q.pop();
		st[a] = false;
		for(auto& t : edges[a])
		{
			int b = t.first, c = t.second;

			if(dist[a] + c < dist[b])
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
	spfa();
	return 0;
}