#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<int, int> mp;
int main()
{
	int n;
	cin >> n;
	mp[0] = 0;
	int sum = 0;
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		x = (x == 0 ? -1 : 1);
		sum += x;
		if(mp.count(sum)) ret = max(ret, i - mp[sum]);
		else mp[sum] = i;
	}
	cout << ret << endl;
	return 0;
}