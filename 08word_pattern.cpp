// https://leetcode.com/problems/word-pattern/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int ct = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i]==' ')ct++;
        }
        if(pattern.size()-1!=ct) return false;

        int start = 0;
        map<char, string>mp;
        map<string, char>mp2;
        for(int i=0;i<pattern.size();i++) {
            char ch = pattern[i];
            string temp;
            while(start<s.size() && s[start]!=' ') {
                temp.push_back(s[start++]);
            }
            if(mp.find(ch)!=mp.end()) {
                if(mp[ch]!=temp) return false;
            }
            if(mp2.find(temp)!=mp2.end()) {
                if(mp2[temp]!=ch) return false;
            }
            mp[ch] = temp;
            mp2[temp] = ch;
            start++;
        }
        return true;
    }
};