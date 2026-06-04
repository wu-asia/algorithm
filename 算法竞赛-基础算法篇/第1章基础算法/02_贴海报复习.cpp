#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;
const int N = 1010;
int n, m;
int a[N], b[N];
int disc[N * 4];
int pos;
int w[N * 4]; //表示海报是第几次贴上去的
bool st[N * 4];
unordered_map<int, int> id;

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i];
		disc[++pos] = a[i] + 1;
		disc[++pos] = b[i];
		disc[++pos] = b[i] + 1;
	}

	//离散化
	sort(disc + 1, disc + 1 + pos);
	int cnt = 0;
	for(int i = 1; i <= pos; i++)
	{
		int x = disc[i];
		if(id.count(x)) continue;
		cnt++;
		id[x] = cnt;
	}

	//模拟贴海报
	for(int i = 1; i <= m; i++)
	{
		int l = id[a[i]], r = id[b[i]];
		for(int j = l; j <= r; j++)
			w[j] = i;
	}

	//统计结果
	int ret = 0;
	for(int i = 1; i <= cnt; i++)
	{
		int x = w[i];
		//x为零和x已经统计过直接跳过循环
		if(!x || st[x]) continue;
		ret++;
		st[x] = true;
	}
	cout << ret << endl;
	return 0;
}