class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        
        vector<int> adj[n];
        vector<int> degree(n, 0);
        
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        
        queue<int> q;
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            ans.clear();
            int sz = q.size();
            
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                
                for (auto it : adj[node]) {
                    degree[it]--;
                    if (degree[it] == 1) {
                        q.push(it);
                    }
                }
            }
        }
        
        return ans;
    }
};
