#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

typedef long long LL;
const int N = 2e4 + 10;
LL a[N], b[N];
LL disc[N * 2];
LL pos;
LL f[N * 2];//差分数组
int n;
unordered_map<int, int> id;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i];
		disc[++pos] = b[i];
	}
	//离散化
	sort(disc + 1, disc + 1 + pos);
	pos = unique(disc + 1, disc + 1 + pos) - (disc + 1);
	for(int i = 1; i <= pos; i++)
	{
		id[disc[i]] = i;
	}

	for(int i = 1; i <= n; i++)
	{
		int l = id[a[i]], r = id[b[i]];
		f[l]++, f[r]--;
	}
	//还原数组
	for(int i = 1; i <= pos; i++) f[i] += f[i - 1];

	LL ret = 0;
	for(int i = 1; i <= pos; i++)
	{
		LL j = i;
		while(j <= pos && f[j] > 0)
			j++;
		ret += disc[j] - disc[i];
		i = j;
	}
	cout << ret << endl;
	return 0;
}