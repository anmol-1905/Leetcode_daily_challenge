// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size()==1) {
            if(k%2==0) return nums[0];
            else return -1;
        } 
        if(k==1) {
            if(nums.size()>=2) return nums[1];
            else return -1;
        }
        if(nums.size()<k) return *max_element(nums.begin(), nums.end());
        else {
            int maxEle = -1;
            int maxInd = -1;
            for(int i=0;i<=k && i<nums.size();i++) {
                if(maxEle<nums[i]) {
                    maxEle = nums[i];
                    maxInd = i;
                }
            }
            if(nums.size()==k) {
                if(maxInd==nums.size()-1) return *max_element(nums.begin(), nums.end()-1);
                else return *max_element(nums.begin(), nums.end());
            }
            if(maxInd==k) return nums[maxInd];
            if(maxInd==k-1) {
                return max(*max_element(nums.begin(), nums.begin()+maxInd),
                        *max_element(nums.begin()+maxInd+1, nums.begin()+maxInd+1+k-maxInd));
            }else {
                return *max_element(nums.begin(), nums.begin()+k);
            }
        }
    }
};