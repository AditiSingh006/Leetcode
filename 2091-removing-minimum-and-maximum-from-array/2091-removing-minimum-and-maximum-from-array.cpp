class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        int min_idx, max_idx;

        for(int i=0; i<n; i++){
            if(nums[i]<mini){
                mini = nums[i];
                min_idx = i;
            }

            if(nums[i]>maxi){
                maxi = nums[i];
                max_idx = i;
            }
        }

        int left = min(min_idx, max_idx);
        int right = max(min_idx, max_idx);

        int fromLeft = right + 1;
        int fromRight = n - left;
        int fromBoth = (left + 1) + (n - right);

        return min({fromLeft, fromRight, fromBoth});
    }
};