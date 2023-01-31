// https://leetcode.com/problems/gas-station/description/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int>vect(n);
        int sum = 0;
        for(int i=0;i<gas.size();i++) {
            vect[i] = gas[i]-cost[i];
            sum+=vect[i];
        }
        if(sum<0) return -1;
        sum = 0;
        int startInd = -1;
        bool isFixed=false;
        for(int i=0;i<n;i++) {
            sum+=vect[i];
            if(sum<0) {
                sum = 0;
                isFixed = false;
            } else {
                if(isFixed==false)
                    startInd = i;
                isFixed = true;
            }
        }   
        return startInd;
    }
};