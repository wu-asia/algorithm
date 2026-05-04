#include<iostream>

using namespace std;

const int N = 1e6 + 10;
int a[N], b[N], c[N];
int la, lb, lc;

bool cmp(string& x, string& y)
{
	if(x.size() != y.size()) 
		return x.size() < y.size();

	return x < y;
}
void sub(int c[], int a[], int b[])
{
	for(int i = 0; i < lc; i++)
	{
		c[i] += a[i] - b[i];
		if(c[i] < 0)
		{
			c[i + 1] -= 1;
			c[i] += 1;
		}
	}

	while(lc > 1 && c[lc - 1] == 0)
		lc--;
}

int main()
{
	string x, y;
	cin >> x >> y;
	if(cmp(x, y))
	{
		swap(x, y);
		cout << "-";
	}

	la = x.size();
	lb = y.size();
	lc = max(la, lb);
	for(int i = 0; i < la; i++)
		a[la - i - 1] = x[i] - '0';
	for(int i = 0; i < lb; i++)
		b[lb - i - 1] = y[i] - '0';
	sub(c, a, b);

	for(int i = lc - 1; i >= 0; i--)
		cout << c[i];
	return 0;
}


// #include<iostream>
// #include<string>
// using namespace std;

// string add(string a, string b)
// {
// 	a = a.find_first_not_of('0') == string::npos ? "0" : a.substr(a.find_first_not_of('0'));
// 	b = b.find_first_not_of('0') == string::npos ? "0" : b.substr(b.find_first_not_of('0'));
// 	reverse(a.begin(), a.end());
// 	reverse(b.begin(), b.end());
// 	int lena = a.size();
// 	int lenb = b.size();
// 	int len = max(a.size(), b.size()) + 2;
// 	string ans(len, '0');
// 	for(int i = 0; i < lena; i++)
// 		ans[i] = a[i];
// 	int t = 0;
// 	for(int i = 0; i < len; i++)
// 	{
// 		if(i < lenb)
// 			t += ans[i] - '0' + b[i] - '0';
// 		else
// 			t += ans[i] - '0';
// 		ans[i] = t % 10 + '0';
// 		t /= 10;
// 	}
// 	reverse(ans.begin(), ans.end());
// 	return (ans.find_first_not_of('0') == string::npos ? "0" : ans.substr(ans.find_first_not_of('0')));
// }
// string sub(string a, string b)
// {
// 	//make sure a > b
// 	a = a.find_first_not_of('0') == string::npos ? "0" : a.substr(a.find_first_not_of('0'));
// 	b = b.find_first_not_of('0') == string::npos ? "0" : b.substr(b.find_first_not_of('0'));
// 	reverse(a.begin(), a.end());
// 	reverse(b.begin(), b.end());
// 	while(b.size() < a.size())
// 		b += "0";
// 	string ans = a;
// 	int n = ans.size();
// 	for(int i = 0; i < n; i++)
// 	{
// 		int numa = ans[i] - '0';
// 		int numb = b[i] - '0';
// 		if(numa >= numb)
// 		{
// 			ans[i] = numa - numb + '0';
// 		}
// 		else
// 		{
// 			int t = 1;
// 			while(i + t < n && ans[i + t] == '0')
// 			{
// 				ans[i + t] = '9';
// 				t++;
// 			}
// 			ans[i] = (numa - numb + 10) + '0';
// 			ans[i + t] -= 1;
// 		}
// 	}
// 	reverse(ans.begin(), ans.end());
// 	return (ans.find_first_not_of('0') == string::npos ? "0" : ans.substr(ans.find_first_not_of('0')));
// }
// int main()
// {

// 	return 0;
// }