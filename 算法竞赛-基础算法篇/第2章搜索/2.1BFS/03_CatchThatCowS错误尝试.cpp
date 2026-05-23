#include<iostream>
using namespace std;

int t;
int x, y;
char dx[] = {'+', '-', '*'};

int bfs(int x, int y)
{
	int cnt = 0;
	int ret = 0;
	while(x < y)
	{
		x *= 2;
		cnt++;
	}
	ret = cnt + min(x - y, y - x / 2);
	return ret;
}
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> x >> y;
		cout << bfs(x, y) << endl;
		//cout << ret << endl;
	}
	return 0;
}