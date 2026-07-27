#include<iostream>

using namespace std;
typedef long long LL;
const LL p = 1000000007;

LL qpow(LL a, LL b, LL q)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1) ret = ret * a % p;
        a = a * a % p;
    }
    return ret % p;
}

int main()
{
    LL n;
    while(cin >> n)
    {
        LL ret = (((n % p) * ((n + 1) % p) * ((2 * n + 1) % p)) * qpow(6, p - 2, p)) % p;
        cout << ret << endl;
    }
    
    return 0;
}