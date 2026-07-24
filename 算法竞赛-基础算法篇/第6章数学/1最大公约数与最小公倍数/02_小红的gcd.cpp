#include<iostream>
#include<string>

using namespace std;
typedef long long LL;



LL mod(string a, LL b)
{
    LL t = 0;
    for(auto ch : a)
    {
        t = t * 10 + (ch - '0');
        t %= b;
    }
    return t;
}

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    
    string a;
    LL b;
    cin >> a >> b;
    cout << gcd(b, mod(a, b)) << endl;
    return 0;
}