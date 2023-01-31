// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/

class Solution {
public:

    void dfs(int source, int par, vector<int>adj[], string &labels, vector<vector<int>>&record) {
        int currLabel = labels[source]-'a';
        record[source][currLabel]+=record[source][currLabel]+1;
        for(auto it: adj[source]) {
            if(it==par)continue;
            dfs(it, source, adj, labels, record);
            for(int i=0;i<26;i++) {
                record[source][i]+=record[it][i];
            }
        }
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>record(n, vector<int>(26, 0));
        dfs(0, -1, adj, labels, record);
        vector<int>ans(n, 0);
        for(int i=0;i<n;i++) {
            ans[i] = record[i][labels[i]-'a'];
        }
        return ans;
    }
};