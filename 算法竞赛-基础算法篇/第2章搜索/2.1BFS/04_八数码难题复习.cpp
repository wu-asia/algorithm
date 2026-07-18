#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;
string aim = "123804765";
string s;

unordered_map<string, int> dist;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs()
{
	queue<string> q;
	dist[s] = 0;
	q.push(s);
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		int pos = 0;
		while(t[pos] != '0') pos++;
		int x = pos / 3, y = pos % 3;
		for(int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || b < 0 || a >= 3 || b >= 3)
				continue;
			string tmp = t;
			int p = 3 * a + b;
			swap(tmp[p], tmp[pos]);
			if(dist.count(tmp)) continue;
			dist[tmp] = dist[t] + 1;
			q.push(tmp);
			if(tmp == aim) return;
		}
	}
}
int main()
{
	cin >> s;
	bfs();
	cout << dist[aim] << endl;
	return 0;
}