// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>hsh(n, 0);
        queue<int>q;
        for(auto it: rooms[0]) {
            q.push(it);
            hsh[it] = 1;
        }
        hsh[0] = 1;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(auto it: rooms[top]) {
                if(hsh[it])continue;

                q.push(it);
                hsh[it] = 1;
            }
        }

        for(int i=0;i<n;i++) {
            if(hsh[i]==0)return false;
            cout << hsh[i] << " ";
        }
        return true;
    }
};