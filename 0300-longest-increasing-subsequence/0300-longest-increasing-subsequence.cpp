class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n=nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int prev=ind-1;prev>=-1;prev--){
        //         int not_take=dp[ind+1][prev+1];
        //         int take=0;
        //         if(prev==-1 || nums[ind]>nums[prev]){
        //             take=1+dp[ind+1][ind+1];
        //         }
        //         dp[ind][prev+1]=max(take,not_take);
        //     }
        // }
        // return dp[0][0];
        int n=nums.size();
        vector<int>curr(n+1,0);
        vector<int>after(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int not_take=after[prev+1];
                int take=0;
                if(prev==-1 || nums[ind]>nums[prev]){
                    take=1+after[ind+1];
                }
                curr[prev+1]=max(take,not_take);
            }
        }
        return after[0];
    }
};