#include<iostream>
#include<string>

using namespace std;
int n;
string path;
void dfs()
{
	if(path.size() == n)
	{
		cout << path << endl;
		return;
	}
	//不选
	path += 'N';
	dfs();
	//回溯 + 剪枝
	path.pop_back();
	//选
	path += 'Y';
	dfs();
	path.pop_back();
}
int main()
{
	cin >> n;
	dfs();
	return 0;
}