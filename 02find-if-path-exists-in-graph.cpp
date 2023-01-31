// https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
public:

    void dfs(vector<int>adj[], int source, vector<bool>&visi) {
        visi[source] = true;
        for(auto it: adj[source]) {
            if(visi[it])continue;
            dfs(adj, it, visi);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visi(n, 0);
        dfs(adj, source, visi);
        return visi[destination];
    }
};