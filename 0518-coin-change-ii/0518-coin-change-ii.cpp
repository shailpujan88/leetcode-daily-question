class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
    //    vector<vector<int>> dp(n, vector<int>(amount+1,0));
    //     for (int t = 0; t <= amount; t++) {
    //         if (t % coins[0] == 0) dp[0][t] = 1;
    //     }
 
    //    for( int ind=1;ind<n;ind++){
    //     for(int target=0;target<=amount;target++){
    //         long not_take=dp[ind-1][target];
    //         long take=0;
    //         if(coins[ind]<=target){
    //             take=dp[ind][target-coins[ind]];
    //         }
    //         dp[ind][target]=not_take+take;
    //     }
    //    }
    //    return dp[n-1][amount];
    //------------------------------------------------------------------>
    //tablulation
    //------------------------------------------------------------------------->


     vectorint> prev(amount+1,0);
     vectorint> curr(amount+1,0);
    for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) prev[t] = 1;
        }
 
       for( int ind=1;ind<n;ind++){
        for(int target=0;target<=amount;target++){
            long not_take=prev[target];
            long take=0;
            if(coins[ind]<=target){
                take=curr[target-coins[ind]];
            }
            curr[target]=not_take+take;
        }
        prev=curr;
       }
       return prev;
    }
};