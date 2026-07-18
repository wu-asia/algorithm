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
    if (s == aim) return 0;
    dist[s] = 0;
    queue<string> q;
    q.push(s);

    while (!q.empty())
    {
        string t = q.front();
        q.pop();
        int step = dist[t];

        // 取出时最多9步，因为生成新串step+1=10直接拦截
        for (int i = 0; i < n; ++i)
        {
            size_t pos = 0;
            while ((pos = t.find(x[i], pos)) != string::npos)
            {
                string tmp = t.substr(0, pos) + y[i] + t.substr(pos + x[i].size());
                // 1. 提前判目标，命中直接返回，不进队列
                if (tmp == aim)
                    return step + 1;
                // 2. 生成新串先判断步数，≥10直接跳过，不存map、不入队
                if (step + 1 >= 10)
                {
                    pos++;
                    continue;
                }
                // 3. 未访问才处理
                if (dist.count(tmp))
                {
                    pos++;
                    continue;
                }
                dist[tmp] = step + 1;
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
    while (cin >> x[n] >> y[n]) n++;
    int ret = bfs();
    if (ret == -1) cout << "NO ANSWER!\n";
    else cout << ret << '\n';
    return 0;
}