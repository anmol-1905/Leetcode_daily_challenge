// https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        vector<int>ans;
        st.push({temperatures[temperatures.size()-1], temperatures.size()-1});
        ans.push_back(0);
        for(int i=temperatures.size()-2;i>=0;i--) {
            while((!st.empty()) && st.top().first<=temperatures[i]) {
                st.pop();
            }
            if(st.size()==0) {
                ans.push_back(0);
            } else {
                ans.push_back(abs(st.top().second-i));
            }
            st.push({temperatures[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};