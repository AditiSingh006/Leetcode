class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n,false);
        int maxn = INT_MIN;

        for(int i=0; i<n; i++){
            maxn = max(maxn, candies[i]);
        }

        for(int i=0; i<n; i++){
            if((candies[i]+extraCandies)>=maxn) ans[i] = true;
        }

        return ans;
    }
};