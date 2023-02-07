// https://leetcode.com/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i = 0;
        int j = 0;
        int n = fruits.size();
        int maxLen = 0;
        while(j<n) {
            mp[fruits[j]]++;
            if(mp.size()<=2) {
                maxLen = max(maxLen, j-i+1);
            } else {
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)mp.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return maxLen;
    }
};