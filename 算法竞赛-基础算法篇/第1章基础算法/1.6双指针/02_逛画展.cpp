#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;
int n, m;
const int N = 1e6 + 10;
int a[N];
struct node
{
	int left, right, range;
};

bool cmp(node& x, node& y)
{
	return x.range < y.range;
}
int main()
{
	unordered_map<int, int> mp;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int type = 0;
	vector<node> ret;
	int range = 0;
	for(int left = 1, right = 1; right <= n; right++)
	{
		//进窗口
		mp[a[right]]++;
		if(mp[a[right]] == 1) type++;
		//更新结果
		while(type == m)
		{
			ret.push_back({left, right, right - left + 1});
			mp[a[left]]--;
			if(mp[a[left]] == 0)
				type--;
			left++;
		}

	}
	sort(ret.begin(), ret.end(), cmp);
	int min_range = ret[0].range;
	int flag = 0;
	int r = ret[0].right;
	for(int i = 0; i < ret.size(); i++)
	{
		if(ret[i].range == min_range)
		{
			if(ret[i].right	< r)
			{
				r = ret[i].right;
				flag = i;
			}
		}
		else
		{
			break;
		}
	}
	cout << ret[flag].left << " " << ret[flag].right << endl;
	return 0;
}