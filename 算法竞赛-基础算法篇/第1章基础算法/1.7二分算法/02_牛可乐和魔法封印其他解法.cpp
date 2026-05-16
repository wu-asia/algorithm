
#include<iostream>

using namespace std;
const int N = 1e5 + 10;


int n;
int a[N];

int binary_search(int x, int y)
{
    int left = 0, right = n - 1;
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(a[mid] >= x) right = mid;
        else left = mid + 1;
    }
    if(a[left] < x) return 0;
    int tmp = left;
    left = 0;
    right = n - 1;
    while(left < right)
    {
        int mid = (left + right + 1) / 2;
        if(a[mid] <= y) left = mid;
        else right = mid - 1;
    }
    if(a[left] > y) return 0;
    
    return right - tmp + 1;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int q;
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << binary_search(x, y) << endl;
    }
    return 0;
}

