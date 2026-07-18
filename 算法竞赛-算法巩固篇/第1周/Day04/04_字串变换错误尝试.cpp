#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;
string s, aim;
const int N = 10;
int n;
string x[N], y[N];
unordered_map<string, int> dist;

int bfs()
{
	if(s == aim) return 0;
	dist[s] = 0;
	queue<string> q;
	q.push(s);
	while(q.size())
	{
		string t = q.front();
		q.pop();

		if(dist[t] >= 10) return -1;
		for(int i = 0; i < n; i++)
		{
			size_t pos = 0;
			while((pos = t.find(x[i], pos)) != string::npos)
			{
				string tmp = t.substr(0, pos) + y[i] + t.substr(pos + x[i].size());
				if(dist.count(tmp)) continue;
				dist[tmp] = dist[t] + 1;
				
				if(tmp == aim) return dist[tmp];
				q.push(tmp);
				pos++;
			}
		}
	}
	return -1;
}
int main()
{
	cin >> s >> aim;
	while(cin >> x[n] >> y[n]) n++;
	int ret = bfs();

	if(ret == -1) cout << "NO ANSWER!" << endl;
	else cout << ret << endl;

	return 0;
}