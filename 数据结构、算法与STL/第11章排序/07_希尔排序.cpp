#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

void shell_sort()
{
    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        for(int i = gap + 1; i <= n; i++)
        {
            int tmp = a[i];
            int j = i - gap;

            while(j > 0 && a[j] > tmp)
            {
                a[j + gap] = a[j];
                j -= gap;
            }

            a[j + gap] = tmp;
        }
    }
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	shell_sort();
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}