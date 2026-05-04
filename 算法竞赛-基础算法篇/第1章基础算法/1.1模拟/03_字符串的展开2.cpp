#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int p1, p2, p3;
string s;
string ret;

bool isdeg(char ch)
{
	return ch >= '0' && ch <= '9';
}

bool islet(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

void add(char left, char right)
{
	string tmp;
	for(int i = left + 1; i < right; i++)
	{
		char t = i;
		if(p1 == 2 && islet(t))
			t = t - 32;
		if(p1 == 3)
			t = '*';
		for(int j = 1; j <= p2; j++)
		{
			tmp += t;	
		}
	}
	if(p3 == 2)
		reverse(tmp.begin(), tmp.end());
	ret += tmp;
}
int main()
{
	cin >> p1 >> p2 >> p3;
	//p1 = 1, 填写小写
	//p1 = 2, 填写大写
	//p1 = 3, 填写星号
	//p2 = k, 中间的字符重复k次
	//p3 = 1, 正序
	//p3 = 2, 逆序
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i++)
	{
		char ch = s[i];
		if(ch != '-' || i == 0 || i == n - 1)
			ret += ch;
		else
		{
			char left = s[i - 1], right = s[i + 1];
			if(isdeg(left) && isdeg(right) && left < right ||
				islet(left) && islet(right) && left < right)
				add(left, right);
			else
				ret += ch;
		}
	}
	cout << ret << endl;
	return 0;
}