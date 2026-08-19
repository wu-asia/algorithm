#include<iostream>
#include<unordered_map>

using namespace std;

typedef long long LL;
const int N = 2e6 + 10;
int m;
LL s[N];
int main()
{
	unordered_map<LL, int> mp;
	cin >> m;
	mp[0] = 0;
	for(int i = 1; i < m; i++)
	{
		
		s[i] = s[i - 1] + i;
		if(mp.count(s[i] - m))
		{
			cout << mp[s[i] - m] + 1 << " " << i << endl;
		} 
		mp[s[i]] = i;
	}

	return 0;
}