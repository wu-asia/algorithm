#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N = 25;
int n, w;
int c[N];
unordered_map<int, int> mp;
int s[N];
int ret;
int main()
{
	cin >> n >> w;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		//mp[c[i]]++;
	}
	sort(c + 1, c + 1 + n);
	for(int i = n; i >= 1; i--)
	{
		for(int j = 1; j <= n; j++)
		{
			if(c[i] + s[j] <= w)
			{
				s[j] += c[i];
				break;
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if(s[i])
			ret++;
		else
			break;
	}
	cout << ret << endl;
}