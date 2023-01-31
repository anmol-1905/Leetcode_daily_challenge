// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:

    void dfs(int node, set<int>paths[], vector<int>&temp, vector<vector<int>>&ans) {
        if(node==0) {
            temp.push_back(0);
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            temp.pop_back();
            return;
        }

        temp.push_back(node);
        for(auto it: paths[node]) {
            dfs(it, paths, temp, ans);
        }
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        set<int>paths[n];
        queue<int>q;
        q.push(0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it: graph[node]) {
                paths[it].insert(node);
                q.push(it);
            }
        }
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(n-1, paths, temp, ans);
        return ans;
    }
};