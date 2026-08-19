#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<unordered_map>

using namespace std;

vector<string> a;
int main()
{
	string s1;
	cin >> s1;
	unordered_map<string, pair<int, int>> mp;

	for(auto& ch : s1)
	{
		if(ch >= 'A' && ch <= 'Z')
		{
			ch = ch + ('a' - 'A');
		}
	}
	string s;
	while(cin >> s)
	{
		a.push_back(s);
	}
	int pos = 0;
	for(auto& e : a)
	{
		for(auto& ch : e)
		{
			if(ch >= 'A' && ch <= 'Z')
			{
				ch = ch + ('a' - 'A');
			}
		}
		if(!mp.count(e))
		{
			mp[e].second = pos;
		}
		mp[e].first++;
		pos += (e.size() + 1);
	}

	if(mp.count(s1))
	{
		cout << mp[s1].first << " " << mp[s1].second << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}