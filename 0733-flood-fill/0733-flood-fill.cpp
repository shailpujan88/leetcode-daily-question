class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     int n = image.size(), m = image[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int initial=image[sr][sc];
        image[sr][sc]=color;
        vis[sr][sc]=color;
        q.push({sr,sc});
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]!=color&&image[nrow][ncol]==initial){
                    vis[nrow][ncol]=color;
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
       return image;

    }
};