#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
typedef pair<int, int> PII;
//pair中的first是重量，second是价值
const int N = 1010;
int n, m;
vector<PII> a[N];
int f[N][N];
//f[i][j]表示从[1, i]组中选出的重量不超过j的最大价值
int main()
{
	cin >> m >> n;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		//x表示重量，y表示价值，z表示组数
		cnt = max(cnt, z);
		a[z].push_back({x, y});
	}
	//f[0][0] = 0未选择重量不超过0的价值也是0
	for(int i = 1; i <= cnt; i++)
	{
		for(int j = m; j >= 0; j--)
		{
			//不选
			f[i][j] = f[i - 1][j];
			for(auto& t : a[i])
			{
				int x = t.first, y = t.second;
				if(j >= x)
					f[i][j] = max(f[i][j], f[i - 1][j - x] + y);
			}
		}
	}
	cout << f[cnt][m] << endl;
	return 0;
}