#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

string s;
string aim = "123804765";
unordered_map<string, int> dist;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void bfs()
{
	queue<string> q;
	q.push(s);
	dist[s] = 0;
	while(q.size())
	{
		string tmp = q.front();
		q.pop();
		int pos = 0;
		while(tmp[pos] != '0') pos++;
		int x = pos / 3, y = pos % 3;
		for(int k = 0; k < 4; k++)
		{
			int a = x + dx[k], b = y + dy[k];
			if(a >= 0 && a <= 2 && b >= 0 && b <= 2)
			{
				
				string next = tmp;
				int p = a * 3 + b;
				swap(next[p], next[pos]);
				if(dist.count(next)) continue;
				dist[next] = dist[tmp] + 1;
				q.push(next);
				if(next == aim) return;
			}
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