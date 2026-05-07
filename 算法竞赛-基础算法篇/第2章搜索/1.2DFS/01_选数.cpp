#include<iostream>
#include<cmath>

using namespace std;

typedef long long LL;
const int N = 1000;
int n, k;
int a[N];
LL ret = 0;
LL cnt = 0;

// bool is_prime(LL num)
// {
// 	if(num == 0 || num == 1)
// 		return false;
// 	else if(num == 2)
// 		return true;
// 	else if(num % 2 == 0)
// 		return false;
// 	for(int i = 3; i <= sqrt(num); i += 2)
// 	{
// 		if(num % i == 0)
// 			return false;
// 	}

// 	return true;
// }

bool is_prime(LL num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    // 只走 6k ± 1 的数，速度提升 3~10 倍
    for (LL i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

void dfs(int pos, int begin)
{
	if(pos > k)
	{
		if(is_prime(ret))
		{
			cnt++;
		}
		return;
	}
	for(int i = begin; i <= n; i++)
	{
		ret += a[i];
		dfs(pos + 1, i + 1);
		ret -= a[i];
	}
}
int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 1);
	cout << "cnt:" << cnt << endl;
	return 0;
}