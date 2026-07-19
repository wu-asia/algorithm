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
	if(!calc(n)) {cout << -1 << endl;
	return 0;}
	int sz = st.size();
	//cout << st.size() << endl;

	for(int i = sz; i > 0; i--)
	{
		int x = (1 << (i - 1)) * st.top();
		st.pop();
		if(x == 0) continue;
		cout << x << " ";
	}
	cout << endl;
	return 0;
}