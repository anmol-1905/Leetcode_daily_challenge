// https://leetcode.com/problems/single-threaded-cpu/description/

class Solution {
public:

    struct Compare {
        bool operator()(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b)
        {
            if(a.first.second==b.first.second) {
                return a.second>b.second;
            }
            return a.first.second>b.first.second;
        }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<pair<pair<int,int>,int>>vp;
        for(int i=0;i<tasks.size();i++) {
            vp.push_back({{tasks[i][0], tasks[i][1]}, i});
        }
        sort(vp.begin(), vp.end());
        for(auto it: vp) {
            cout << it.first.first <<" " << it.first.second <<"\n";
        }
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, Compare>pq;
        vector<int>ans;
        int i = 0;
        int n = tasks.size();
        int totalTime = 0;
        while(i<n) {
            if(pq.size()==0) {
                totalTime+=vp[i].first.first;
                pq.push(vp[i]);
                i++;
            } else {
                int startTime = pq.top().first.first;
                int endTime = pq.top().first.second;
                int ind = pq.top().second;
                pq.pop();
                totalTime += (endTime);
                ans.push_back(ind);
                while(i<n && vp[i].first.first<=totalTime) {
                    pq.push(vp[i]);
                    i++;
                }
                
            }
        }
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};