class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maximum=0;
        int ans=0;
        int curr=0;
        for(int num:nums){
            if(maximum<num){
                maximum=num;
                ans=curr=0;
            }
            if(maximum==num){
                curr++;

            }else{
                curr=0;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};