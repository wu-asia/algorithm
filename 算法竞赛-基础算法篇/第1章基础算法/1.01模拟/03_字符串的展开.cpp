#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int p1, p2, p3;
string s;
string ret;

bool isdeg(char ch)
{
	if((ch - '0') >= 0 && (ch - '0') <= 9)
		return true;
	return false;
}

bool islet(char ch)
{
	if((ch - 'a') >= 0 && (ch - 'a') <= 25)
		return true;
	return false;
}

void add(char left, char right)
{
	string tmp;
	int n = (right - left + 1) * p2;
	if(p1 == 1)
	{
		for(char i = left + 1; i < right; i++)
		{
			for(int j = 1; j <= p2; j++)
			{
				tmp += i;
			}
		}
	}
	else if(p1 == 2)
	{
		for(char i = left + 1; i < right; i++)
		{
			if(islet(i))
			{
				for(int j = 1; j <= p2; j++)
				{
					tmp += (i - 32);
				}
			}
			else
			{
				for(int j = 1; j <= p2; j++)
				{
					tmp += i;
				}
			}
		}
	}
	else
	{
		tmp = string(n, '*');
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