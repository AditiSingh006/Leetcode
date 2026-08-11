class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int j = 1;
        while(j<n && nums[j]-nums[j-1]==1){
            sum = sum + nums[j];
            j++;
        }
        
        unordered_set<int> s(nums.begin(), nums.end());

        while (s.count(sum)) {
            sum++;
        }

        return sum;
    }
};