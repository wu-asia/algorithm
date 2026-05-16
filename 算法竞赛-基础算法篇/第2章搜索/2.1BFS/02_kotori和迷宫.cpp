#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
#include<climits>
#include<algorithm>
#include<string>

using namespace std;
typedef pair<int, int> PII;
const int N = 40;
int n, m, x, y;
char a[N][N];
int dist[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs()
{
    memset(dist, -1, sizeof dist);
    queue<PII> q;
    q.push({x, y});
    dist[x][y] = 0;
    while(q.size())
    { 
        auto t = q.front();
        q.pop();
        int i = t.first, j = t.second;   
        for(int k = 0; k < 4; k++)
        {
       
            int x1 = i + dx[k], y1 = j + dy[k];
//             if(x1 < 1 || x1 > n || y1 < 1 || y1 > m)
//                 continue;
//             if(a[x1][y1] == '*') continue;
//             if(dist[x1][y1] != -1) continue;
//             if(a[x1][y1] == 'e') continue;
//             dist[x1][y1] = dist[i][j] + 1;
//             q.push({x1, y1});
            if(x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && a[x1][y1] != '*' && dist[x1][y1] == -1)
            {
                
                dist[x1][y1] = dist[i][j] + 1;
                
                if(a[x1][y1] == 'e')
                    continue;
                q.push({x1, y1});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'k')
            {
                x = i;
                y = j;
            }
        }
    }
    bfs();
    int ret = INT_MAX;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(dist[i][j] != -1 && a[i][j] == 'e')
            {
                ret = min(ret, dist[i][j]);
                cnt++;
            }
        }
    }
    if(cnt)
        cout << cnt << " " << ret << endl;
    else
        cout << -1 << endl;
    return 0;
}