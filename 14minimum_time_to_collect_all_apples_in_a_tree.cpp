// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

class Solution {
public:
    int total = 0;
    void setLevel(int source, int par, vector<int>adj[], vector<int>&levels, int level) {
        levels[source] = level;
        for(auto it: adj[source]){
            if(it==par)continue;
            setLevel(it, source, adj, levels, level+1);
        }
    }

    pair<bool, int> couldFindTrue(int source, int par, vector<int>adj[], vector<bool>&hasApple, vector<int>&levels) {
        vector<pair<bool, int>>temp;
        for(auto it: adj[source]) {
            if(it==par)continue;
            auto itr = couldFindTrue(it, source, adj, hasApple, levels);
            if(itr.first==true) {
                temp.push_back(itr);
            }
        }
        if(temp.size()==2) {
            total+=(2*levels[temp[0].second]+2*levels[temp[1].second]-4*levels[source]);
            return {true, source};
        } else if(temp.size()==1){
            total+=(2*levels[temp[0].second]-2*levels[source]);
            return {true, source};

        }
        if(temp.size()!=0) {
        for(int i=0;i<temp.size();i++) {
            total+=(2*levels[temp[i].second]-2*levels[source]);
        }
        return {true, source};
        }
        if(hasApple[source]) {
            return {true, source};
        } else {
            return {false, -1};
        }
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>Levels(n, 0);
        setLevel(0, -1, adj, Levels, 0);
        int ele = couldFindTrue(0, -1, adj, hasApple, Levels).second;
        return total;
    }
};