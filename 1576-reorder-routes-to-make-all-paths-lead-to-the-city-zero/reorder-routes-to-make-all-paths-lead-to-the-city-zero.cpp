class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Adj list: {neighbour, is_original_edge}
        // is_original_edge = 1 (अगर रास्ता u से v है)
        // is_original_edge = 0 (अगर हमने रास्ता v से u खुद जोड़ा है)
        vector<vector<pair<int, int>>> adj(n);
        
        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 1}); // Original Edge (0 से दूर जा रही है)
            adj[v].push_back({u, 0}); // Fake/Reverse Edge (0 की तरफ आ रही है)
        }
        
        int change_count = 0;
        vector<bool> visited(n, false);
        
        // Lambda function for DFS
        auto dfs = [&](auto& self, int node) -> void {
            visited[node] = true;
            
            for (auto& neighbour_pair : adj[node]) {
                int neighbour = neighbour_pair.first;
                int is_original = neighbour_pair.second;
                
                if (!visited[neighbour]) {
                    // अगर रास्ता node से neighbour की तरफ जा रहा है (is_original == 1),
                    // तो यह Capital (0) से दूर जा रहा है। इसे बदलना पड़ेगा।
                    if (is_original == 1) {
                        change_count++;
                    }
                    // Neighbour के बच्चों को Recursively चेक करें
                    self(self, neighbour);
                }
            }
        };
        
        // Capital node (0) से DFS शुरू करें
        dfs(dfs, 0);
        
        return change_count;
    }
};
