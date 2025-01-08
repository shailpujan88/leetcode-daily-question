/*
Pseudocode:
1. Initialize variables:
   - V as the number of nodes in the graph
   - adjRev as a reversed graph (vector of vectors)
   - indegree as an array to count the number of incoming edges for each node

2. Build the reversed graph:
   - For each node `i` in the graph:
     - For each neighbor `it` of `i`:
       - Add `i` to adjRev[it] (reverse the edge)
       - Increment indegree[i] to count its incoming edge

3. Initialize a queue `q` and a vector `safenode` to store safe nodes.

4. Push all nodes with indegree 0 into the queue:
   - For each node `i`, if indegree[i] == 0, push `i` into `q`.

5. Process nodes from the queue:
   - While the queue is not empty:
     - Pop a node from the front of the queue.
     - Add it to `safenode`.
     - For each neighbor `it` of the node in adjRev:
       - Decrement indegree of `it`.
       - If indegree of `it` becomes 0, push it into the queue.

6. Sort `safenode` in increasing order.

7. Return `safenode`.
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();  // Number of nodes
        vector<vector<int>> adjRev(V);  // Reversed graph
        vector<int> indegree(V, 0);  // Indegree array

        // Build the reversed graph and calculate indegrees
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                adjRev[it].push_back(i);  // Reverse edge
                indegree[i]++;  // Increment indegree
            }
        }

        queue<int> q;
        vector<int> safenode;

        // Add all nodes with indegree 0 to the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process nodes using topological sort
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safenode.push_back(node);
            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safenode.begin(), safenode.end());  // Sort result
        return safenode;
    }
};
