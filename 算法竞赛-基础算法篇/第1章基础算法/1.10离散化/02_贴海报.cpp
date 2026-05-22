#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;
const int N = 1010;
int n, m;
int a[N], b[N];
int pos;
int disc[N * 4];
unordered_map<int, int> id;

int w[N * 4]; //海报墙
bool st[N * 4]; //标记那些数字出现过
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i]; disc[++pos] = a[i] + 1;
		disc[++pos] = b[i]; disc[++pos] = b[i] + 1;
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
	// 在离散化的基础上，模拟贴海报的过程
	for(int i = 1; i <= m; i++)
	{
		//离散话之后的值 a[i] ~ b[i]
		int l = id[a[i]], r = id[b[i]];
		for(int j = l; j <= r; j++)
		{
			w[j] = i;
		}

	}
	//统计结果 - 数组中有多少个不同的数
	int ret = 0;
	for(int i = 1; i <= cnt; i++)
	{
		int x = w[i];
		if(!x || st[x]) continue;
		ret++;
		st[x] = true;
	}
	cout << ret << endl;
	return 0;
}