// https://leetcode.com/problems/find-the-town-judge/description/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>adj[n+1];
        vector<int>indegree(n+1, 0);
        for(int i=0;i<trust.size();i++) {
            int a = trust[i][0];
            int b = trust[i][1];
            adj[a].push_back(b);
            indegree[b]++;
        }
        for(int i=1;i<=n;i++) {
            if(indegree[i]==n-1 && adj[i].size()==0) {
                return i;
            }
        }
        return -1;
    }
};