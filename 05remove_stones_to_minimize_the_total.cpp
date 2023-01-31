// https://leetcode.com/problems/remove-stones-to-minimize-the-total/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0;i<piles.size();i++) {
            pq.push(piles[i]);
        }
        while(k--) {
            int t = pq.top();
            pq.pop();
            pq.push((t/2)+(t%2!=0));
        }
        int sum = 0;
        while(pq.size()>0) {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};