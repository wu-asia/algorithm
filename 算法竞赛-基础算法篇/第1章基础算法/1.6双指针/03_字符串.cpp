#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string s;
int main()
{
    cin >> s;
    unordered_map<char, int> mp;
    int ret = s.size();
    int kind = 0;
    for(int left = 0, right = 0; right < s.size(); right++)
    {
        //进窗口
        if(mp[s[right]] == 0) kind++;
        mp[s[right]]++;
        //判断
        while(kind == 26)
        {
            ret = min(ret, right - left + 1);
            mp[s[left]]--;
            if(mp[s[left]] == 0) kind--;
            left++;
        }
    }
    cout << ret << endl;
    return 0;
}