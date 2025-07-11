class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // int n = prices.size();
        // if (n == 0 || k == 0) return 0;
        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int buy = 0; buy <= 1; buy++) {
        //         for (int cap = 1; cap <= k; cap++) {
        //             if (buy == 1) {
        //                 dp[ind][buy][cap] =
        //                     max(-prices[ind] + dp[ind + 1][0][cap],
        //                         0 + dp[ind + 1][1][cap]);
        //             } else {
        //                 dp[ind][buy][cap] =
        //                     max(prices[ind] + dp[ind + 1][1][cap - 1],
        //                         dp[ind + 1][0][cap]);
        //             }
        //         }
        //     }
        // }
        // return dp[0][1][k];
        // //------------------------------------------------------------------------>
        // tabulation
        int n=prices.size();
         vector<vector<int>>cur(2, vector<int>(k+1, 0));
          vector<vector<int>>after(2, vector<int>(k+1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if(buy==1){
                        cur[buy][cap]=max(-prices[ind]+after[0][cap],0+after[1][cap]);
                    }
                    else{
                        cur[buy][cap]=max(prices[ind]+after[1][cap-1],after[0][cap]);
                    }
                }
            }
            after=cur;
        }
        return after[1][k];
    }
};