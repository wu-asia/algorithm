#include<iostream>
using namespace std;

int k, x, y;
//a,b表示棋盘的左上角，len为长度，xy表示障碍物的坐标
void dfs(int a, int b, int len, int x, int y)
{
	if(len == 1) return;
	len /= 2;

	//右下角
	if(x >= a + len && y >= b + len)
	{
		cout << a + len - 1 << " " << b + len - 1 << " " << 4 << endl;
		dfs(a, b, len, a + len - 1, b + len - 1);
		dfs(a, b + len, len, a + len - 1, b + len);
		dfs(a + len, b, len, a + len, b + len - 1);
		dfs(a + len, b + len, len, x, y);
	}	
	//左下角
	else if(x >= a + len && y >= b)
	{
		cout << a + len - 1 << " " << b + len << " " << 3 << endl;
		dfs(a, b, len, a + len - 1, b + len - 1);
		dfs(a, b + len, len, a + len - 1, b + len);
		dfs(a + len, b, len, x, y);
		dfs(a + len, b + len, len, a + len, b + len);
	}
	//右上角
	else if(x >= a && y >= b + len)
	{
		cout << a + len << " " << b + len - 1 << " " << 2 << endl;
		dfs(a, b, len, a + len - 1, b + len - 1);
		dfs(a, b + len, len, x, y);
		dfs(a + len, b, len, a + len, b + len - 1);
		dfs(a + len, b + len, len, a + len, b + len);
	}
	//左上角
	else
	{
		cout << a + len << " " << b + len << " " << 1 << endl;
		dfs(a, b, len, x, y);
		dfs(a, b + len, len, a + len - 1, b + len);
		dfs(a + len, b, len, a + len, b + len - 1);
		dfs(a + len, b + len, len, a + len, b + len);
	}
}
int main()
{
	cin >> k >> x >> y;
	k = (1 << k);
	dfs(1, 1, k, x, y);
	return 0;
}