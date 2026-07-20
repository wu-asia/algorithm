#include<iostream>
#include<string>

using namespace std;

int main()
{
	string n;
	int k;
	cin >> n >> k;
	for(int i = 1; i <= k; i++)
	{
		bool flag = false;
		for(int i = 0; i < n.size(); i++)
		{
			if(n[i] > n[i + 1])
			{
				flag = true;
				n.erase(i, 1);
				break;
			}
		}
		if(!flag) n.pop_back();
	}

	if(n.find_first_not_of('0') == string::npos) cout << "0" << endl;
	else cout << n.substr(n.find_first_not_of('0')) << endl;
	return 0;	
}