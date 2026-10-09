#include<iostream>

using namespace std;
typedef long long LL;

LL exgcd(LL a, LL b, LL& x, LL& y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    LL x1, y1, d;
    d = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return d;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        LL a, b;
        scanf("%lld %lld", &a, &b);
        LL x, y, d;
        d = exgcd(a, b, x, y);
        x = x / d, y = y / d;
        if(d != 1)
        {
            printf("-1\n");
        }
        else
        {
            LL k = b / d;
            x = (x % k + k) % k;
            x = (x == 0 ? k : x);
            printf("%lld\n", x);
        }
    }
    return 0;
}