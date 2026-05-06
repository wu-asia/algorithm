#include<iostream>
#include<string>

using namespace std;

int n;
string path;
void dfs(int pos)
{
	if(pos > n)
	{
		cout << path << endl;
		return;
	}
	//不选
	path += 'N';
	dfs(pos + 1);
	path.pop_back();
	//选
	path += 'Y';
	dfs(pos + 1);
	path.pop_back();
}
int main()
{
	cin >> n;
	dfs(1);
	return 0;
}