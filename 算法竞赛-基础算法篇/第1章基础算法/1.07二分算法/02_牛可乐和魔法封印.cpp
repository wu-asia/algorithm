#include<iostream>

using namespace std;

const int N = 1e5 + 10;
long long n, q;
long long a[N];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> q;
    while(q--)
    {
        long long x, y;
        cin >> x >> y;
        long long left = 0, right = n - 1;
        while(left < right)
        {
            long long mid = (left + right) / 2;
            if(a[mid] < x) left = mid + 1;
            else right = mid;
        }
        long long l = left;
        if(a[left] < x)
        {
            cout << 0 << endl;
            continue;
        }
        left = 0, right = n -1;
        while(left < right)
        {
            long long mid = (left + right + 1) / 2;
            if(a[mid] <= y) left = mid;
            else right = mid - 1;
        }
        if(a[left] > y)
        {
            cout << 0 << endl;
            continue;
        }
        cout << right - l + 1 << endl;
    }
    return 0;
}