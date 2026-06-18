#include<iostream>
using namespace std;

const int N = 1e5 + 10;
const int M = 1e4 + 10;
int n;
int a[N];
int cnt[M];

void counting_sort()
{
	int mx = a[1];
	for(int i = 1; i <= n; i++)
		mx = max(mx, a[i]);
	for(int i = 1; i <= n; i++)
		cnt[a[i]]++;
	int k = 1;
	for(int num = 0; num <= mx; num++)
		while(cnt[num]--)
			a[k++] = num;
			
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