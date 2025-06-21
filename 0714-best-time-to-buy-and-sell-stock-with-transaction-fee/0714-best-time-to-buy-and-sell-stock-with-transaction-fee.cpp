class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // int n=prices.size();
        // vector<vector<int>> dp(n+2,vector<int>(2, 0));
        // for (int ind = n - 1; ind >= 0; ind--) {      
        //                 dp[ind][1]=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
        //                 dp[ind][0]=max(prices[ind]-fee+dp[ind+1][1],0+dp[ind+1][0]);
                    
            
        // }
        // return dp[0][1];
        //tabulation
        int n=prices.size();
        vector<int> curr(2, 0);
        vector<int> after(2, 0);
        for (int ind = n - 1; ind >= 0; ind--) {      
                        curr[1]=max(-prices[ind]+after[0],0+after[1]);
                     curr[0]=max(prices[ind]-fee+after[1],0+after[0]);
                    
           after=curr; 
        }

        return after[1];
    }
};