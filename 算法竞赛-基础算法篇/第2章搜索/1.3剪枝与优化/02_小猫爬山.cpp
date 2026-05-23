#include<iostream>
#include<algorithm>

using namespace std;
const int N = 25;
int n, w;
int ret = N; //ret 是最有的结果
int c[N], s[N];
//c[]表示小猫的重量，s[]表示缆车的数量和承重
int cnt; //缆车的数量
//cmp函数升序排序
bool cmp(int x, int y)
{
	return x > y;
}

void dfs(int pos)
{
	//如果缆车的数量大于最优解的情况，剪枝
	if(cnt > ret) return;
	//所有的小猫都已经上了缆车
	if(pos > n)
	{
		ret = cnt;
		return;
	}
	//先上已经有小猫的缆车
	for(int i = 1; i <= cnt; i++)
	{
		//剪枝
		if(c[pos] + s[i] > w) continue;
		s[i] += c[pos];
		dfs(pos + 1);
		s[i] -= c[pos];
	}
	//再来一辆车
	cnt++;
	s[cnt] = c[pos];
	dfs(pos + 1);
	s[cnt] = 0;
	cnt--;
	
}
int main()
{
	cin >> n >> w;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	sort(c + 1, c + n + 1, cmp);
	dfs(1);
	cout << ret << endl;
	return 0;
}