class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n );
      for (int i = 0; i < roads.size(); i++) {
            int from = roads[i][0];
            int to = roads[i][1];
            int time = roads[i][2];
            adj[from].push_back({to, time});
            adj[to].push_back({from, time});  // Since the graph is undirected
        }

  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int>ways(n,0);
        dist[0] = 0;
        ways[0]=1;
        pq.push({0, 0});

        while (!pq.empty()) {
           int time=pq.top().first;
           int node=pq.top().second;
            pq.pop();
            for (auto neigh_parent : adj[node]) {
                int neighnode = neigh_parent.first;
                int timet = neigh_parent.second;
                long long new_dist = time + timet;
                if (new_dist < dist[neighnode]) {
                    dist[neighnode] = new_dist;
                    pq.push({new_dist, neighnode});
                    ways[neighnode]=ways[node];
                }
                else if(new_dist == dist[neighnode]){
                         ways[neighnode]= (ways[neighnode]+ways[node])%mod;
                }
                
            }
        }
        return ways[n-1]%mod;
    }
};