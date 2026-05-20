//排序 + 离散化 + 哈希表去重以记录最终的位置

#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;
const int N = 1e5 + 10;
int n;
int a[N];
int pos;
int disc[N];
unordered_map<int, int> id;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		disc[++pos] = a[i];

	}
	sort(disc + 1, disc + 1 + pos);
	int cnt = 1; 
	for(int i = 1; i <= pos; i++)
	{
		int x = disc[i];
		if(id.count(x)) continue;
		cnt++;
		id[x] = cnt;
	}
	for(int i = 1; i <= n; i++)
	{
		cout << a[i] << "离散化之后的值" << id[a[i]] << endl;
	}
}