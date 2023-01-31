// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {        
        vector<vector<int>>ans;
        if(intervals.size()==0) {
            ans.push_back(newInterval);
            return ans;
        } 
        if(intervals[0][0]>newInterval[1]) {
            ans.push_back(newInterval);
            for(auto it: intervals){
                ans.push_back(it);
            }
            return ans;
        }
        int i = 0;
        int n = intervals.size();
        bool flag = true; 
        while(i<n) {
            while(i<n && intervals[i][1]<newInterval[0]) {
                ans.push_back(intervals[i]);
                i++;
            }
            if(i==n) {flag = false;break;}
            int start = min(newInterval[0], intervals[i][0]);
            while(i<n && newInterval[1]>=intervals[i][0]) {
                i++;
            }
            if(i==n) {
                ans.push_back({start, max(newInterval[1], intervals[n-1][1])});
            } else {
                i--;
                int end = max(newInterval[1], intervals[i][1]);
                ans.push_back({start, end});
            }
            i++;
            break;
        }
        if(flag==false)
            ans.push_back(newInterval);
        while(i<n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};