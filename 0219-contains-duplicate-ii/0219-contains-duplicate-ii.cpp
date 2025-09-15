class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;
        for (int a = 0; a < nums.size(); a++) {
        if (mapp.find(nums[a]) != mapp.end()) { 
            if (abs(a - mapp[nums[a]]) <= k) {
                 return true;
                } else {
                 mapp[nums[a]] = a;
                }
            } else {
            mapp[nums[a]] = a;
            }
        }
        return false;  
    }
};
