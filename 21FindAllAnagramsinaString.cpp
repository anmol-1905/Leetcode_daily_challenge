// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        map<char,int>mp1, mp2;
        for(auto ch: p) {
            mp1[ch]++;
            mp2[ch]++;
        }   
        int i=0;
        int j=0;
        while(j<s.size()) {
            if(mp1.find(s[j])!=mp1.end()) {
                mp2[s[j]]--;
                if(mp2[s[j]]==0) {
                    mp2.erase(s[j]);
                }
            }
            if(j-i+1<p.size()) {
                j++;
            } else {
                if(mp2.size()==0) {
                    ans.push_back(i);
                }
                if(mp1.find(s[i])!=mp1.end()) {
                    mp2[s[i]]++;
                    if(mp2[s[i]]==0) {
                        mp2.erase(s[i]);
                    }
                }
                i++;
                j++;
            }

        }
        return ans;
    }
};