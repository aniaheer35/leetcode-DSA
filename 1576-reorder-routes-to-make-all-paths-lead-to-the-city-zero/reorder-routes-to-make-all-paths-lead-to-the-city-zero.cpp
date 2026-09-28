class Solution {
public:
    int count = 0;

    void dfs(int node, int parent, vector<vector<pair<int,int>>>& adj) {
        for(auto it : adj[node]) {
            int neighbour = it.first;
            int direction = it.second;

            if(neighbour == parent) {
                continue;
            }

            if(direction == 1) {
                count++;
            }

            dfs(neighbour, node, adj);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto connection : connections) {
            int u = connection[0];
            int v = connection[1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        dfs(0, -1, adj);

        return count;
    }
};