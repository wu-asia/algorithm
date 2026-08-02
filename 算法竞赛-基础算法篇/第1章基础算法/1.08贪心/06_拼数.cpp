#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> a;
int n;

bool cmp(string& x, string& y)
{
	return x + y > y + x;
}
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		a.push_back(s);
	}

	sort(a.begin(), a.end(), cmp);

	for(auto e : a)
		cout << e;
	cout << endl;
	return 0;
}