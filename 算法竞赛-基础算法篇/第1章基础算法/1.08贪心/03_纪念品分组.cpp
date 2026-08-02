#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 3e4 + 10;
int w, n;
LL a[N];
int main()
{
	cin >> w >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	LL ret = 0;
	int left = 1, right = n;
	while(left < right)
	{
		if(a[left] + a[right] <= w)
		{
			ret++;
			left++;
			right--;
		}
		else
		{
			ret++;
			right--;
		}
	}
	if(left == right) ret++;
	cout << ret << endl;
	return 0;
}