#include<iostream>
#include<string>

using namespace std;
typedef long long LL;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		LL sum = 0;
		bool flag = false;
		for(auto ch : s)
		{
			if(ch == '0')
				flag = true;
			sum += ch - '0';
		}
		if(flag) cout << sum + 9 << endl;
		else cout << sum + 8 << endl;
	}
	return 0;
}