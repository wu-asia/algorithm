#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n, m;
string s, t;
string ret = "";

int main()
{
    cin >> n >> m;
    getchar();
    cin >> s >> t;
    sort(t.begin(), t.end());
    int pos1 = 0, pos2 = 0;
    while(pos1 < s.size() && pos2 < t.size())
    {
        if(s[pos1] < t[pos2])
            ret.push_back(s[pos1++]);
        else
            ret.push_back(t[pos2++]);
    }
    while(pos1 < s.size()) ret.push_back(s[pos1++]);
    while(pos2 < t.size()) ret.push_back(t[pos2++]);

    for(int i = 0; i < ret.size(); i++)
        cout << ret[i];
    cout << endl;
    return 0;
}