#include<iostream>

using namespace std;

const int N = 210;
int st[][5] = {
	0, -1, 1, 1, -1,
	1, 0, -1, 1, -1,
	-1, 1, 0, -1, 1,
	-1, -1, 1, 0, 1,
	1, 1, -1, -1, 0
};

int a[N], b[N];
int main()
{
	int n, na, nb;
	cin >> n >> na >> nb;
	for(int i = 0; i < na; i++)
		cin >> a[i];
	for(int i = 0; i < nb; i++)
		cin >> b[i];
	int reta = 0, retb = 0;
	for(int i = 0; i < n; i++)
	{
		if(st[a[i % na]][b[i % nb]] == 1)
			reta++;
		else if(st[a[i % na]][b[i % nb]] == -1)
			retb++;
	}
	cout << reta << " " << retb << endl;
	return 0;
}