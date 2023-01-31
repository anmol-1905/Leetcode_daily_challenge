// https://leetcode.com/problems/best-team-with-no-conflicts/


class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int,int>>vect;
        for(int i=0;i<n;i++) {
            vect.push_back({ages[i], scores[i]});
        }
        sort(vect.begin(), vect.end());
        vector<int>dp(n, 0);
        for(int i=0;i<n;i++) {
            dp[i] = vect[i].second;
            for(int j=0;j<i;j++) {
                if(vect[i].first==vect[j].first) {
                    dp[i] = max(vect[i].second+dp[j], dp[i]);
                }else if(vect[j].second<=vect[i].second) {
                    dp[i] = max(dp[j]+vect[i].second, dp[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};