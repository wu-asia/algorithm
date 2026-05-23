#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;
typedef long long LL;
int n, c;
const int N = 2e5 + 10;
unordered_map<int, LL> mp;
LL a[N];
int main()
{
	cin >> n >> c;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	//sort(a + 1, a + n + 1);
	LL ret = 0;
	for(int i = 1; i <= n; i++)
	{
		//cout << "sum:" << a[i] + c << " ";
		if(mp.count(a[i] + c))
		{
			ret++;
		}
	}
	cout << ret << endl;
	return 0;
}