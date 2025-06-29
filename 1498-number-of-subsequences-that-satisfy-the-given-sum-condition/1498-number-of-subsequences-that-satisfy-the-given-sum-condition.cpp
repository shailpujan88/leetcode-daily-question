class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for(int i;i<nums.size();i++){
            if(i>0) continue;
        int ll = 0;
        int rr = nums.size() - 1;                        
                                                           
                                                         
if(nums[i]+nums[i]<=target && nums[i]+nums[ll]<=target&&nums[i]+nums[rr] <=target nums[ll]+nums[rr]<=target){
    cnt++;  
}                               
    }
    }
};