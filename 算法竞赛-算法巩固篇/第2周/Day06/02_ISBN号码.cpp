#include<iostream>
#include<string>
#include<sstream>


using namespace std;


string str(int num)
{
	if(num == 10)
		return "X";
	string s;
	stringstream ss;
	ss << num;
	ss >> s;
	return s;
}

int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	int ret = 0;
	for(int i = 0; i < s.size() - 2; i++)	
		if(s[i] >= '0' && s[i] <= '9')
		{
			cnt++;
			ret += (s[i] - '0') * cnt;
		}
	ret %= 11;
	int num = s[s.size() - 1] - '0';
	if(s[s.size() - 1] == 'X') num = 10;
	
	if(ret == num) cout << "Right" << endl;
	else cout << s.substr(0, s.size() - 1) + str(ret) << endl;
	return 0;
}