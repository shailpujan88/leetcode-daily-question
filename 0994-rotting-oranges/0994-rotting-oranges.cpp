class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cntfresh=0;//
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } 
                else {
                    vis[i][j] = 0;
                }
                if(grid[i][j]==1){ cntfresh++;}
            }
        }
        int time = 0;
        int cnt=0;//
        int delrow[] = {-1, 0, +1, 0};
        int delcol[]= {0, +1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for (int i = 0;i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && vis[nrow][ncol]== 0) {
                    q.push({{nrow, ncol}, time + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;//
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (vis[i][j] != 2 && grid[i][j] == 1) {
        //             return -1;
        //         }
        //     }
        // }//this is all a way too check any organe remoain unrotten
        if(cnt!=cntfresh) return -1;//

        // where this is u can remove the // part and 
        return time;
    }
};