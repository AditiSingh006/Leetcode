class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n,0);
        int maxx = INT_MIN;
        for(int i=0; i<n; i++){
            maxx = max(maxx,nums[i]);
            maxi[i] = maxx;
        }

        vector<int> mini(n,0);
        int minn = INT_MAX;
        for(int i=n-1; i>=0; i--){
            minn = min(minn,nums[i]);
            mini[i] = minn;
        }

        for(int i=0; i<n; i++){
            if((maxi[i]-mini[i])<=k) return i;
        }

        return -1;
    }
};