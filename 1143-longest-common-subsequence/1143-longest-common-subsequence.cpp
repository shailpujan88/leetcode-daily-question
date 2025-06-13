class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<=n;i++) return dp[i][0]=0;
            for(int j=0;j<=m;j++)return dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i<0||j<0) return 0;
                if(text1[i-1]==text2[j-1])
                    dp[i][j]= 1 +dp[i-1][j-1];
                  else  return max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};