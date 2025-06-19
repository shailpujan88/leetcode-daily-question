class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++) dp[i][0]=i;
          for(int j=1;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
 if(word1[i-1]==word2[j-1]){
    dp[i][j]=dp[i-1][j-1];
 }
 else{
   int ddelete= 1+dp[i-1][j];
   int insert= 1+dp[i][j-1];
   int replace=1+dp[i-1][j-1];
   dp[i][j]=min(insert,min(ddelete,replace));
 }
            }
        }
//         int m=word1.size();
//         int n=word2.size();
//           vector<int> prev(n + 1, 0), curr(n + 1, 0);
//     for (int j = 1; j <= n; ++j){
//       prev[j] = j;}
//  for (int i = 1; i <= m; ++i){
//       curr[0] = i;
//       for(int j=1;j<=n;j++){
//                 if(word1[i-1]==word2[j-1]){
//                     curr[j]=prev[j-1];
//                 }
//                 else{
//                     int insert=curr[j-1]+1;
//                     int dele=prev[j]+1;
//                     int repl=prev[j-1]+1;
//                     curr[j]=min(insert,min(dele,repl));
//                 }

//       }
//       prev=curr;
//       }
//       return prev[n];
return dp[n][m];
    }

};