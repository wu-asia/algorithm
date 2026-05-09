#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
const int N = 100;
int n, k;
int a[N];
bool st[N];
LL path;
int ret;
// bool is_prime(int num)
// {
// 	if(num <= 1) return false;
// 	else if(num == 2) return true;
// 	else if(num % 2 == 0) return false;
// 	for(int i = 3; i <= i * num; i += 2)
// 	{
// 		if(num % i == 0) 
// 			return false;
// 	}
// 	return true;
// }


bool is_prime(LL num) 
{
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    // 只走 6k ± 1 的数，速度提升 3~10 倍
    for (LL i = 5; i * i <= num; i += 6) 
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}
void dfs(int pos, int begin)
{
	if(pos > k)
	{
		if(is_prime(path))
			ret++;
		return;
	}

	for(int i = begin; i <= n; i++)
	{
		path += a[i];
		dfs(pos + 1, i + 1);
		path -= a[i];
	}
}
int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 1);
	cout << ret << endl;
	return 0;
}

