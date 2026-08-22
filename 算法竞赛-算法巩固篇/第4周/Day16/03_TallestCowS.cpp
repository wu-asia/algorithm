#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

const int N = 1e4 + 10;

int n, I, H, r;
int f[N];

int main()
{
	cin >> n >> I >> H >> r;
	set<pair<int, int>> st;

	while(r--)
	{
		int a, b; cin >> a >> b;
		if(st.count({a, b})) continue;
		st.insert({a, b});
		if(a > b) swap(a, b);
		//[a + 1, b - 1]
		f[a + 1]++;
		f[b]--;
	}

	for(int i = 1; i <= n; i++)
	{
		f[i] += f[i - 1];
		//cout << f[i] << " ";
		cout << H - f[i] << endl;
	}
	return 0;
}