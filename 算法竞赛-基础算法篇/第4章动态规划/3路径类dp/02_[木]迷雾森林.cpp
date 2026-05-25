#include<iostream>
using namespace std;

const int N = 3e3 + 10;
int n, m;
int a[N][N];
int f[N][N];

void read(int& n)
{
    char c;
    c = getchar();
    while(c != '1' && c != '0')
        c = getchar();
    n = c - '0';
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            read(a[i][j]);
    f[n][0] = 1;
    for(int i = n; i >= 1; i--)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == 1) continue;
            f[i][j] = (f[i + 1][j] + f[i][j - 1]) % 2333;
        }
    }

//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= m; j++)
//         {
//             cout << f[i][j] << " ";
//         }
//         cout << endl;
//     }
    cout << f[1][m] << endl;
}