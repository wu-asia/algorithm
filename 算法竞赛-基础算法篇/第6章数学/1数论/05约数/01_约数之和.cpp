#include<iostream>

using namespace std;

int n;
int main()
{
    cin >> n;
    int ret = 0;
    for(int i = 1; i <= n / i; i++)
    {
        if(n % i == 0)
        {
            ret += i;
            if(n / i != i)
                ret += n / i;
        }
    }
    cout << ret << endl;
    return 0;
}