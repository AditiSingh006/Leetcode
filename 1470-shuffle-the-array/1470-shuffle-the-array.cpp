class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        for(int i=0; i<n; i++){
            nums[i] = nums[i] | (nums[i+n]<<16);
        }
        
        int j = 2*n - 1;
        for(int i=n-1; i>=0; i--){
            int k = nums[i];
            nums[j--] = (k>>16) & 0xFFFF;
            nums[j--] = k & 0xFFFF;
        }

        return nums;
    }
};