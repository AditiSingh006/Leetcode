class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxs = INT_MIN;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
            maxs = max(sum, maxs);
            if(sum<0) sum = 0;
        }
        return maxs;
    }
};