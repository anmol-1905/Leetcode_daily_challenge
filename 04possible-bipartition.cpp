// https://leetcode.com/problems/possible-bipartition/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int s, int color, vector<int>&visi, vector<int>adj[]) {
        visi[s] = color;
        for(auto it: adj[s]) {
            if(visi[it]!=-1 && visi[it]==color) return true;
            if(visi[it]==-1 && dfs(it, !color, visi, adj)) return true;
        }
        return false;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(int i=0;i<dislikes.size();i++) {
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int>visi(n+10, -1);
        for(int i=1;i<=n;i++) {
            if(visi[i]==-1) {
                if(dfs(i, 0, visi, adj)) return false;
            }
        }
        return true;
    }
};