#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

int n, m;
const int N = 1e6 + 10;
int a[N];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int left = 1, right = 1;
	int ret = n, begin = 1;
	int kind = 0;
	unordered_map<int, int> mp;
	while(right <= n)
	{
		//进窗口
		if(mp[a[right]] == 0)
			kind++;
		mp[a[right]]++;
		//
		while(kind == m)
		{
			//更新结果
			int len = right - left + 1;
			if(len < ret)
			{
				ret = len;
				begin = left;
			}
			//出窗口
			mp[a[left]]--;
			if(mp[a[left]] == 0)
				kind--;
			left++;
		}
		right++;
	}

	cout << begin << " " << begin + ret - 1 << endl;
	return 0;
}