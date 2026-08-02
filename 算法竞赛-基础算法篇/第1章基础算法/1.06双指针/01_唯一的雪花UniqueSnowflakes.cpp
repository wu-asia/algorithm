#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;

const int N = 1e6 + 10;

int a[N];
int t;
int main()
{
	cin >> t;
	while(t--)
	{
		unordered_map<int, int> mp;
		int n = 0;
		int x = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int ret = INT_MIN;
		for(int left = 1, right = 1; right <= n; right++)
		{
			//进窗口
			mp[a[right]]++;
			//判断
			while(mp[a[right]] > 1)
			{
				//出窗口
				mp[a[left]]--;
				left++;
			}
			//更新结果
			ret = max(ret, right - left + 1);
		}
		cout << ret << endl;
	}
	return 0;
}