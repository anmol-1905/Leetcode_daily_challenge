class Solution {
public:
    
    string gcdOfStrings(string str1, string str2) {
        string ans;
        if(str1.size()<str2.size()) {
            swap(str1, str2);
        }
        int n = str1.size();
        int m = str2.size();
        for(int i=m;i>0;i--) {
            if(n%i==0 && m%i==0) {
                string temp = str2.substr(0, i);
                cout << temp <<"\n";
                int index = 0;
                bool flag = true;
                for(int j=0;j<n;j++) {
                    if(str1[j]!=temp[index]) {
                        flag = false;
                        break;
                    }
                    index = (index+1)%temp.size();
                }
                if(flag && index==0) {
                    for(int j=0;j<m;j++) {
                        if(str2[j]!=temp[index]) {
                            flag = false;
                            break;
                        }
                        index = (index+1)%temp.size();
                    }
                    if(flag==true && index==0) return temp;
                }
            }
        }
        return "";
    }
};