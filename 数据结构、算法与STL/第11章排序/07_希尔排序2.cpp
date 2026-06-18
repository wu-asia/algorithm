#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];
void shell_sort()
{
	for(int gap = n / 2; gap > 0; gap /= 2)
	{
		//对于间隔为gap的数组元素使用插入排序
		for(int i = gap + 1; i <= n; i++)
		{
			int key = a[i];
			int j = i - gap;
			while(j > 0 && key < a[j])
			{
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = key;
		}
	}
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	shell_sort();
	for(int j = 1; j <= n; j++)
		cout << a[j] << " ";
	cout << endl;
	return 0;
}