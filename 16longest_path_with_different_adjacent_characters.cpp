// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

class Solution {
public:
    int ans = INT_MIN;
    int dfs(int source, vector<int>adj[], string &s) {
        int maxpathFromMe = 0;
        int first = 0;
        int second = 0;
        for(auto it: adj[source]) {
            int val = dfs(it, adj, s);
            if(s[source]!=s[it]) {
                maxpathFromMe = max(maxpathFromMe, val);
                if(first==0) {
                    first = val;
                } else {
                    if(second==0) {
                        second = val;
                        if(first>second)swap(first, second);
                    } else if(min(first, second)<val) {
                        first = second;
                        second = val;
                        if(first>second)swap(first, second);
                    }
                }
            }
        }
        ans = max(ans, first+second+1);
        return maxpathFromMe+1;
        
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int>adj[n];
        for(int i=0;i<parent.size();i++) {
            if(parent[i]==-1) continue;
            adj[parent[i]].push_back(i);
        }
        dfs(0, adj, s);
        return ans;
    }
};