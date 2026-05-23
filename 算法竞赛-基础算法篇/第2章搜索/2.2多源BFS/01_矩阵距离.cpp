#include<iostream>
#include<utility>
#include<queue>
#include<cstring>

using namespace std;
typedef pair<int, int> PII;
const int N = 1010;
char a[N][N];
int dist[N][N];
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs()
{
    memset(dist, -1, sizeof dist);
    queue<PII> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] == '1')
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        for(int k = 0; k < 4; k++)
        {
            int a = x + dx[k], b = y + dy[k];
            if(a >= 1 && a <= n && b >= 1 && b <= m && dist[a][b] == -1)
            {
                dist[a][b] = dist[x][y] + 1;
                q.push({a, b});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    bfs();
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}