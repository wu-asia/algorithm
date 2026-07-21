#include<iostream>
#include<string>

using namespace std;


int main()
{
	string s;
	int k;
	cin >> s >> k;
	for(int i = 1; i <= k; i++)
	{
		bool flag = false;
		for(int j = 0; j < s.size() - 1; j++)
		{
			if(s[j] > s[j + 1])
			{
				s.erase(j, 1);
				flag = true;
				break;
			}
		}
		if(!flag) s.pop_back();
	}
	if(s.find_first_not_of('0') == string::npos) cout << "0" << endl;
	else cout << s.substr(s.find_first_not_of('0')) << endl;
	cout << s << endl;
	return 0;
}