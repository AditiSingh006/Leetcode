class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int sum;
        for(int i=0; i<nums.size(); i++){
            sum = 0;
            int k = nums[i];
            while(k){
                sum = sum + (k%10);
                k = k / 10;
            }
            if(sum==i) return i;
        }
        return -1;
    }
};