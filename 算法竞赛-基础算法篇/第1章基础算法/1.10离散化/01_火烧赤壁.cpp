#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N = 2e4 + 10;
int n;
int a[N], b[N];
int pos;
int disc[N * 2];
unordered_map<int, int> id;
int f[N];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i];
		disc[++pos] = b[i];
	}
	sort(disc + 1, disc + 1 + pos);
	pos = unique(disc + 1, disc + 1 + pos) - (disc + 1);
	for(int i = 1; i <= pos; i++)
	{
		int x = disc[i];
		id[x] = i;
	}

	for(int i = 1; i <= n; i++)
	{
		int l = id[a[i]], r = id[b[i]];
		f[l]++;
		f[r]--;
	}

	for(int i = 1; i <= pos; i++)
		f[i] += f[i - 1];
	int ret = 0;
	for(int i = 1; i <= pos; i++)
	{
		int j = i;
		while(j <= pos && f[j] > 0) j++;
		//i ~ j
		ret += disc[j] - disc[i];
		i = j;
	}
	cout << ret << endl;
	return 0;
}