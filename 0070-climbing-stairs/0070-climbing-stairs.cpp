class Solution {
public:
    int climbStairs(int n) {
    vector<int>dp(n+1,-1);
   return  solve(n,dp);
    }
    //memorisation
    // int solve(int n){
    // if(n<=1) return 1;
    // if(dp[n]!=-1) return dp[n];
    // return dp[n]=climbStairs(n-1)+climbStairs(n-2);
    // }
    int solve(int n,vector<int>dp){
     dp[0]=1;
     dp[1]=1;
     for(int i=2;i<=n;i++){
     dp[i]=dp[i-1]+dp[i-2];
     }
     return dp[n];
    }
};