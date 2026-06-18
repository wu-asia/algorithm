#include <iostream>
using namespace std;

const int N = 1e5 + 10;
const int M = 100000 + 10;     // 元素最大值范围

int n;
int a[N];
int cnt[M];

void counting_sort()
{
    //找最大值
    int mx = a[1];
    for(int i = 2; i <= n; i++)
        mx = max(mx, a[i]);

    //统计出现次数
    for(int i = 1; i <= n; i++)
        cnt[a[i]]++;

    //按顺序输出
    int k = 1;
    for(int i = 0; i <= mx; i++)
    {
        while(cnt[i]--)
            a[k++] = i;
    }
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    counting_sort();

    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";

    return 0;
}