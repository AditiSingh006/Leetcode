class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1, z = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]!=0) p = p * nums[i];
            else z++;
        }

        for(int i=0; i<n; i++){

            if(z==0){
                nums[i] = p / nums[i];
            }

            else if(z==1){
                if(nums[i]==0) nums[i] = p;
                else nums[i] = 0;
            }

            else{
                nums[i] = 0;
            }
        }

        return nums;
    }
};