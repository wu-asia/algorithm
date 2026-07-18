#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int n;
stack<int> st;
bool calc(int n)
{
	if(n % 2 != 0) return false;
	while(n)
	{
		int num = n % 2;
		st.push(num);
		n /= 2;
	}
	return true;
}
int main()
{
	cin >> n;
	if(!calc(n)) cout << -1 << endl;
	int sz = st.size();
	cout << st.size() << endl;
	while(st.size())
	{
		cout << st.top();
		st.pop();
	}
	cout << endl;
	for(int i = sz; i >= 0; i--)
	{
		int x = pow(2, i) * st.top();
		if(x == 0) continue;
		cout << x << " ";
		st.pop();
	}
	cout << endl;
	return 0;
}