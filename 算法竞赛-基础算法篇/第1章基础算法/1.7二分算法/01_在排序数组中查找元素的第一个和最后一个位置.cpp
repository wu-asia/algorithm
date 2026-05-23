#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(nums.size() == 0) return {-1, -1};
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        int l = left;
        if(nums[l] != target) return {-1, -1};
        left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right + 1) / 2;
            if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid;
        }
        
        return {l, right};
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {5, 7, 7, 8, 8, 10};
	int target = 8;
	vector<int> ret = sol.searchRange(nums, target);

	cout << "[" << ret[0] << ", " << ret[1] << "]" << endl;
	return 0;
}