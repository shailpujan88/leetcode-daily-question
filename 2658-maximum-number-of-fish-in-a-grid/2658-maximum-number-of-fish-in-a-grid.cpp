class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>> vis, int i, int j) {
        queue<pair<int, int>> q;
        int n = grid.size();    // size of row
        int m = grid[0].size(); // size of col
        q.push({i, j});
        vis[i][j] = 1;
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        int cnt = 0;
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            cnt += grid[row][col];
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] != 0 ){
                    q.push({nrow , ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return cnt;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
         int n =grid.size();        // size of row
         int m = grid[0].size(); // size of col
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && vis[i][j] != 1)
                    ans = max(ans, bfs(grid, vis, i, j));
            }
        }
        return ans;
    }
};