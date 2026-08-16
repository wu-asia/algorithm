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
int f[N];
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
	for(int i = 1; i <= cnt; i++)
	{
		for(int j = m; j >= 0; j--)
		{
			for(auto& t : a[i])
			{
				int x = t.first, y = t.second;
				if(j >= x)
					f[j] = max(f[j], f[j - x] + y);
			}
		}
	}
	cout << f[m] << endl;
	return 0;
}