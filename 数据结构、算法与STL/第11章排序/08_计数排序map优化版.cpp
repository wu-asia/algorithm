#include<iostream>
#include<map>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n;

map<int, int> mp;
void counting_sort()
{
	for(int i = 1; i <= n; i++)
		mp[a[i]]++;
	int k = 1;
	for(auto e : mp)
	{
		for(int i = 1; i <= e.second; i++)
			a[k++] = e.first;
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	counting_sort();
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}