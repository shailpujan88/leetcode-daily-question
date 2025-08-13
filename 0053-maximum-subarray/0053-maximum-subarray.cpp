class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0];
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr=max(nums[i],curr+nums[i]);
            maxsum=max(curr,maxsum);
        }
        return maxsum;
    }
};