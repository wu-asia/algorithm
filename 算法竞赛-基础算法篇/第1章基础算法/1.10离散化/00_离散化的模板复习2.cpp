//排序 + 哈希表

#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int n;
int pos;
int disc[N];
unordered_map<int, int> mp;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		disc[++pos] = a[i];
	}
	sort(disc + 1, disc + 1 + n);
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int x = disc[i];
		if(mp.count(x)) continue;
		cnt++;
		mp[x] = cnt;
	}
	for(int i = 1; i <= n; i++)
	{
		cout << mp[a[i]] << " ";
	}
	cout << endl;
	return 0;
}