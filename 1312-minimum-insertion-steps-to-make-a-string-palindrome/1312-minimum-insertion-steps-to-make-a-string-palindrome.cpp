class Solution {
public:
    int minInsertions(string s) {
        // int n=s.size();
        // string t = s;                              
        // reverse(t.begin(), t.end());
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         if(s[i-1]==t[j-1])
        //             dp[i][j]= 1 +dp[i-1][j-1];
        //           else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //     }
        // }
        // return n-dp[n][n];
        int n=s.size();
        string t = s;                              
        reverse(t.begin(), t.end());
       vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1])
                    curr[j]= 1 +prev[j-1];
                  else  curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr
        }
        return n-prev[n];
    }
};