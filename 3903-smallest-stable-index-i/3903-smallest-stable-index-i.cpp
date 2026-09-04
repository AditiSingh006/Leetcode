class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxm;
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            maxm.push_back(maxi);
        }

        vector<int> minm(nums.size());
        int mini = INT_MAX;
        for(int i = nums.size() - 1; i >= 0; i--){
            mini = min(mini, nums[i]);
            minm[i] = mini;
        }

        for(int i=0; i<nums.size(); i++){
            if((maxm[i]-minm[i])<=k){
                return i;
            }
        }

        return -1;
    }
};