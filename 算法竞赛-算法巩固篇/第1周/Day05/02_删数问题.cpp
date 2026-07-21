#include<iostream>
#include<string>

using namespace std;

int main()
{
	string n;
	int k;
	cin >> n >> k;
	for(int j = 1; j <= k; j++)
	{
		bool flag = false;
		for(int i = 0; i < n.size() - 1; i++)
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