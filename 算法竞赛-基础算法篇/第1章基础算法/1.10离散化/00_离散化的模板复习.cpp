// 排序 + 去重 + 二分算法

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N]; //储存元素
int n;
int pos; //储存之后的离散化的元素个数
int disc[N]; //用于储存去重之后的元素

int find(int x)
{
	int left = 1, right = pos;
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(disc[mid] >= x) right = mid;
		else left = mid + 1;
	}
	return left;
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		disc[++pos] = a[i];
	}
	//排序
	sort(disc + 1, disc + 1 + pos);
	//去重 + 更新个数
	pos = unique(disc + 1, disc + 1 + pos) - (disc - 1);
	for(int i = 1; i <= n; i++)
	{
		cout << find(a[i]) << endl;
	}
	return 0;
}