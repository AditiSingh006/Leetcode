class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 1, e = nums[0];
        int n = nums.size();
        
        for(int i=1; i<n; i++){
            if(nums[i]==e){
                c++;
            }
            else{
                c--;
                if (c == 0) {
                    e = nums[i];
                    c = 1;
                }
            }
        }

        return e;
    }
};