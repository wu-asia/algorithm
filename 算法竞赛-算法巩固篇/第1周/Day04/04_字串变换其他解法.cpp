#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

int bfs(string start, string target, vector<string>& from, vector<string>& to)
{
    unordered_map<string, int> dist;
    queue<string> q;
    dist[start] = 0;
    q.push(start);
    if (start == target) return 0;

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        int step = dist[cur];
        if (step >= 10) return -1; // 最多10步限制

        for (int i = 0; i < from.size(); ++i)
        {
            const string& src = from[i];
            const string& dst = to[i];
            size_t pos = 0;
            // 只调用一次find，统一size_t接收
            while ((pos = cur.find(src, pos)) != string::npos)
            {
                string next = cur.substr(0, pos) + dst + cur.substr(pos + src.size());
                if (dist.count(next))
                {
                    pos++;
                    continue;
                }
                dist[next] = step + 1;
                if (next == target)
                    return dist[next];
                q.push(next);
                pos++;
            }
        }
    }
    return -1;
}

int main()
{
    string s, aim, a, b;
    cin >> s >> aim;
    vector<string> x, y;
    while (cin >> a >> b)
    {
        x.push_back(a);
        y.push_back(b);
    }
    int ans = bfs(s, aim, x, y);
    if (ans == -1)
        cout << "NO ANSWER!\n";
    else
        cout << ans << '\n';
    return 0;
}