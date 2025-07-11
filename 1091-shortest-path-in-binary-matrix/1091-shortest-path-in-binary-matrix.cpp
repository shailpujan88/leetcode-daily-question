class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> effort(n, vector<int>(m, 1e9));

        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
            return -1;

        int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        pq.push({1, {0, 0}});
        effort[0][0] = 1;

        while (!pq.empty()) {
            auto pr = pq.top();
            pq.pop();
            int effort_of_par = pr.first;
            int row = pr.second.first;
            int col = pr.second.second;

            if (row == n - 1 && col == m - 1)
                return effort_of_par;

            for (int i = 0; i < 8; i++) {
                int nrow = dx[i] + row;
                int ncol = dy[i] + col;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0) {
                    if (effort_of_par + 1 < effort[nrow][ncol]) {
                        effort[nrow][ncol] = effort_of_par + 1;
                        pq.push({effort[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};
