class Solution {
public:
    int maxSubArray(vector<int>& nums) {
int maxsum=nums[0];
int curr=nums[0];//So the simple rule we can take curr=0 but if we take 0 we are doing cgeating beacuse we should have one element always in subarray
//Start with the first real pile you see//not an imaginary pile of zero. \U0001f36c
        for(int i=1;i<nums.size();i++){
            curr=max(nums[i],curr+nums[i]);
            maxsum=max(curr,maxsum);
        }
        return maxsum;
    }
};