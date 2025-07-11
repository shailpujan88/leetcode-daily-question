class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
    int n=heights.size();
    int m=heights[0].size();
   priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
   vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
   pq.push({0,0,0});
 effort[0][0]=0;
 while(!pq.empty()){
    auto pr=pq.top();
    pq.pop();
    int effort_of_par=pr[0] ,row=pr[1],col=pr[2];
    for(int i=0;i<4;i++){
        int nrow=dx[i]+row;
        int ncol=dy[i]+col;
        if(nrow>=0 && nrow<n&&ncol>=0&&ncol<m){
            int new_effort=max(effort_of_par,abs(heights[row][col]-heights[nrow][ncol]));
            if(new_effort<effort[nrow][ncol]){
                effort[nrow][ncol]=new_effort;
                pq.push({effort[nrow][ncol],nrow,ncol});
            }
        }
    }
 }
return effort[n-1][m-1];
    }
};