class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
               
                    if(buy==1){
                        dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                    }
                    else{
                        dp[ind][buy]=max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]);
                    }
            }
        }
        return dp[0][1];
    //------------------------------------------------------------------------>
   // tabulation
        // int n=prices.size();
        //  vector<vector<int>>cur(2, vector<int>(3, 0));
        //   vector<vector<int>>after(2, vector<int>(3, 0));
        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int buy = 0; buy <= 1; buy++) {
        //         for (int cap = 1; cap <= 2; cap++) {
        //             if(buy==1){
        //                 cur[buy][cap]=max(-prices[ind]+after[0][cap],0+after[1][cap]);
        //             }
        //             else{
        //                 cur[buy][cap]=max(prices[ind]+after[1][cap-1],0+after[0][cap]);
        //             }
        //         }
        //     }
        //     after=cur;
        // }
        // return after[1][2]; 
    }
};