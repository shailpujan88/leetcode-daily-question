class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 0;
                }
            }

        int delro[] = {1, -1, 0, 0};
        int delcol[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + delro[i];
                int ncol = c + delcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    vis[nrow][ncol] == -1) {
                    vis[nrow][ncol] = vis[r][c] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return vis;
    }
};