#include<iostream>

using namespace std;
typedef long long LL;
const LL p = 1000000007;

LL qpow(LL a, LL b, LL p)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret % p;
}

int main()
{
    LL n;
    while(cin >> n)
    {
        LL a = n % p;
        LL b = (n % p + 1);
        LL c = (n % p) * 2  + 1 % p;
        LL q = qpow(6, p - 2, p) % p;
        LL ret = a * b % p * c % p * q % p;
        cout << ret << endl;
    }
    
    return 0;
}