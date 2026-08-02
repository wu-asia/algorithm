#include<iostream>

using namespace std;

typedef long long LL;

LL n;

int main()
{
    LL ret = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j += i)
        {
            ret++;
        }
    }
    cout << ret << endl;
    return 0;
}