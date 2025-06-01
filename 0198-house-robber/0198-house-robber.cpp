class Solution {
public:
    // int rob(vector<int>& nums) {
    //   int n=nums.size();
    //   vector<int>dp(n+1,-1);
    //   return solve(n-1,nums,dp) ;
    // }
    // int solve(int index,vector<int>& nums,vector<int>& dp){

    //     if(index==0) return nums[index];
    //     if(index<0) return 0;
    //      int pick=nums[index]+solve(index-2,nums,dp);
    //      int notpick=0+solve(index-1,nums,dp);
    //      return max(pick,notpick);
    //          }
int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n, 0); // Initialize dp array with 0
    return solve(n, nums, dp);
}
    int solve(int n, vector<int>& nums, vector<int>& dp) {
        dp[0] = nums[0];
        int neg = 0;
        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if(i-2>=0){
                take+=dp[i - 2];
            }
            int nottake = 0 + dp[i - 1];
            dp[i] = max(take, nottake);
        }
        return dp[n - 1];
    }
};