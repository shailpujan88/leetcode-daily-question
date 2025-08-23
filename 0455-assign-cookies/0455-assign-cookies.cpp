class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;
        int r=0;
        while(l<n && r<m){
            if(g[l]<=s[r]){
                l++;
            }
            r++;
        }
        return l;
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(g[i-1]<=s[j-1]){
        //             dp[i][j]=max(dp[i-1][j-1]+1,dp[i-1][j]);
        //         }
        //         else{
        //             dp[i][j]=dp[i-1][j];
        //         }
        //     }
        // }
        //    return dp[n][m];  ///time limit execced in dp

    }
};