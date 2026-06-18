#include<iostream>
#include<ctime>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n;
int get_radom_index(int left, int right)
{
	return (rand() % (right - left + 1)) + left;
}
void quick_sort(int left, int right)
{
	if(left >= right) return;
	int ele = a[get_radom_index(left, right)];
	int l = left - 1, i = left, r = right + 1;
	while(i < r)
	{
		if(ele > a[i]) swap(a[++l], a[i++]);
		else if(ele == a[i]) i++;
		else swap(a[--r], a[i]);
	}
	quick_sort(left, l);
	quick_sort(r, right);
}
int main()
{
	srand(time(NULL));
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	quick_sort(1, n);
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}