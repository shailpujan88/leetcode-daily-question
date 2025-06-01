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
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> dp(n, 0); // Initialize dp array with 0
    //     return solve(n, nums, dp);
    // }
    //     int solve(int n, vector<int>& nums, vector<int>& dp) {
    //         dp[0] = nums[0];
    //         int neg = 0;
    //         for (int i = 1; i < n; i++) {
    //             int take = nums[i];
    //             if(i-2>=0){
    //                 take+=dp[i - 2];
    //             }
    //             int nottake = 0 + dp[i - 1];
    //             dp[i] = max(take, nottake);
    //         }
    //         return dp[n - 1];
    //     }
    // tabulation
    //----------------------------------------------------------------------------->
    int solve(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++){
            int pick = nums[i];
        if (i - 2 >= 0) {
            pick += prev2;
        }
        int nonpick = prev1;
        int curr=max(pick,nonpick);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
    }
    int rob(vector<int> &nums){
        int n=nums.size();
    vector<int> arr1;
    vector<int> arr2;
    
    if(n==1)
       return nums[0];
    
    for(int i=0; i<n; i++){
        
        if(i!=0) arr1.push_back(nums[i]);
        if(i!=n-1) arr2.push_back(nums[i]);
    }
    
   int ans1 = solve(arr1);
     int ans2 = solve(arr2);
    
    return max(ans1,ans2);
}
};