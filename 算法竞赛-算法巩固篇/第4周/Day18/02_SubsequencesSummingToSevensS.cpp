#include<iostream>
#include<unordered_map>

using namespace std;

int n;

int main()
{
	cin >> n;
	unordered_map<int, int> mp;
	mp[0] = 0;
	int ret = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		sum = (sum + x) % 7;
		if(mp.count(sum)) ret = max(ret, i - mp[sum]);
		else mp[sum] = i;
	}
	cout << ret << endl;
	return 0;
}