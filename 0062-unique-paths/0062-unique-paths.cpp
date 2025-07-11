class Solution {
public:
    int uniquePaths(int m, int n) {
        //    vector<vector<int>> dp(m,(vector<int>(n)));
        //     dp[0][0] = 1;
        //     for(int i=0;i<m;i++){
        //         for(int j =0;j<n;j++){
        //             int up=0;
        //             int left=0;
        //             if(i-1>=0)  up = dp[i-1][j];
        //             if(j-1>=0)  left = dp[i][j-1];
        //             int sum=0;
        //             sum+= up+left;
        //             dp[i][j]+=sum;
        //         }
        //     }
        //     return dp[m-1][n-1];

        vector<int> prev(n, 1); // Base case: first row is all 1s

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prev[j] = prev[j] + prev[j - 1];
            }
        }

        return prev[n - 1];
    }
};