#include<iostream>
#include<unordered_map>

using namespace std;

int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int calc(int x)
{
	if(x == 0) return a[0];
	int ret = 0;
	while(x)
	{
		ret += a[x % 10];
		x /= 10;
	}
	return ret;
}
int main()
{
	//cout << calc(10) << endl;
	int n;
	cin >> n;
	n -= 4;
	//cout << " n" << n << endl;
	unordered_map<int, int> mp;
	
	for(int i = 0; i <= 999; i++)
	{
		mp[calc(i) + calc(i) + calc(i + i)]++;
	}
	for(int i = 0; i < 999; i++)
	{
		for(int j = 0; j < 999; j++)
		{
			if(i == j) continue;
			mp[calc(i) + calc(j) + calc(i + j)]++;
		}
	}
	cout << mp[n] << endl;
	return 0;
}