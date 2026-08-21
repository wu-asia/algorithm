#include<iostream>
#include<string>

using namespace std;

string s1, s2;
int main()
{
	cin >> s1;
	cin.ignore();
	getline(cin, s2);
	for(auto& e : s1)
	{
		e = tolower(e);
	}
	for(auto& e : s2)
	{
		e = tolower(e);
	}
	s1 = " " + s1 + " ";
	s2 = " " + s2 + " ";
	int cnt = 0;
	int f = 0;
	if(s2.find(s1) == string::npos)
	{
		cout << -1 << endl;
	}
	else
	{
		f = s2.find(s1);
		int pos = 0;
		while(s2.find(s1, pos) != string::npos)
		{
			pos = s2.find(s1, pos);
			cnt++;
			pos++; 
		}
		cout << cnt << " " << f << endl;
	}
	return 0;
}