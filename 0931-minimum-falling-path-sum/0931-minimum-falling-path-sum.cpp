class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //     int m=triangle.size();
        //   vector<vector<int> > dp(m, vector<int>(m, -1));
        //    return minpath(0,0,triangle,m,dp);
        // }
        // int minpath(int i,int j,vector<vector<int>>& triangle,int
        // m,vector<vector<int>>& dp){
        //     if(dp[i][j]!=-1) return dp[i][j];
        //     if(i==m-1) return triangle[i][j];
        //     int down =triangle[i][j]+minpath(i+1,j,triangle, m, dp);
        //     int diagonal=triangle[i][j]+minpath(i+1,j+1,triangle, m, dp);
        //     return dp[i][j]=min(down,diagonal)
        // memo
        ///---->tc-o(n)(n)
        //--->sc o(n*n) o(n)
        //-------------------------------------------------------------------------------->
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize first row
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[i - 1][j];

                int ld = matrix[i][j];
                if (j - 1 >= 0) {
                    ld += dp[i - 1][j - 1];
                } else {
                    ld += 1e9; // Just ignore this path
                }

                int rd = matrix[i][j];
                if (j + 1 < n) {
                    rd += dp[i - 1][j + 1];
                } else {
                    rd += 1e9; // Just ignore this path
                }

                dp[i][j] = min(up, min(ld, rd));
            }
        }

        // Final answer is the max in last row
        int maxi =  INT_MAX;
        for (int j = 0; j < n; j++) {
            maxi = min(maxi, dp[m - 1][j]);
        }

        return maxi;
        // tabulation
        // tc-o(n*n)
        // sc-o(n*n)
        //------------------------------------------------------------------------------------->
        // int m = matrix.size();
        // int n = matrix[0].size();
        //         vector<int> front(m, 0);
        //          vector<int> curr(m, 0);
        //           vector<int> curr2(m, 0);
        //         for (int j = 0; j < m; j++) {
        //            front[j]=matrix[m-1][j];
        //         }
        //         for (int i = m - 2; i >= 0; i--) {
        //             for (int j = i; j >= 0; j--) {
        //                 int down = matrix[i][j] + front[j];
        //                 int diagonalleft = matrix[i][j] + front[j + 1];
        //                 int diaright=matrix[i][j] + front[j - 1];
        //                 curr[j]=min(diagonalleft,diaright);
        //                  curr2[j]=min(down,curr);
        //             }
        //             front=curr;
        //         }
        //         return front[0];
        //         ////space optimisation
        //         //tc-o(n*n)
        //         //sc(o(n)
    }
};