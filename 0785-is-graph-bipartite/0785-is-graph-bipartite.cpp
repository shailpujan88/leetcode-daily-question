class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int col,
             int node) {
        color[node] = col;

        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                if (!dfs(graph, color, 1 - col, neighbor)) {
                    return false;
                }
            } else if (color[neighbor] == col) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                if (!dfs(graph, color, 0, i)) {
                    return false;
                }
            }
        }

        return true;
    }
};