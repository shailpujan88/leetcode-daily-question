class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});  

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        while (!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();

            for (auto& it : adj[node]) {
                int nextNode = it.first;
                int nextTime = it.second;

                if (currTime + nextTime < dist[nextNode]) {
                    dist[nextNode] = currTime + nextTime;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int ans = *max_element(dist.begin()+1, dist.end());
        return ans == 1e9 ? -1 : ans;
    }
};