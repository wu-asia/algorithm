#include<iostream>

using namespace std;

int n;
int v[10];
int main()
{
	cin >> n;
	for(int i = 1; i <= 6; i++)
		cin >> v[i];
	int ret = 0, cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		if(x)
		{
			cnt++;
			if(cnt >= 1 && cnt < 3)
				ret += v[1];
			else if(cnt >= 3 && cnt < 7)
				ret += v[2];
			else if(cnt >= 7 && cnt < 30)
				ret += v[3];
			else if(cnt >= 30 && cnt < 120)
				ret += v[4];
			else if(cnt >= 120 && cnt < 365)
				ret += v[5];
			else
				ret += v[6];
		}
		else
			cnt = 0;
	}
	cout << ret << endl;
	return 0;
}