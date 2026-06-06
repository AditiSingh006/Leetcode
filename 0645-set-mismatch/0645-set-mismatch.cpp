class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> c(n+1,0);
        int u = 0, d = 0;

        for(int n : nums){
            c[n]++;
        }

        for(int i=1; i<=n; i++){
            if(c[i]==2) d = i;
            else if(c[i]==0) u = i;
        }

        return {d,u};
    }
};