class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
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
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            dp[m-1][j]=triangle[m-1][j];
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j]=min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};