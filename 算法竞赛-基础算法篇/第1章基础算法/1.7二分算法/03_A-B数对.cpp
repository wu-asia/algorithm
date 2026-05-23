#include<iostream>
#include<algorithm>

typedef long long LL;
using namespace std;
const int N = 2e5 + 10;
LL a[N];
LL ret;
int n;
int c;
int binary_search(int t)
{
	int left = 1, right = n;
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(a[mid] < t) left = mid + 1;
		else right = mid;
	}
	if(a[left] != t) return 0;
	int tmp = left;
	left = 1, right = n;
	while(left < right)
	{
		int mid = (left + right + 1) / 2;
		if(a[mid] > t) right = mid - 1;
		else left = mid;
	}
	if(a[right] != t) return 0;

	return right - tmp + 1;

}
int main()
{
	cin >> n >> c;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		int target = a[i] + c;
		int ans = binary_search(target);
		if(target == a[i]) ans--;
		ret += ans;
	}
	cout << ret << endl;
	return 0;
}