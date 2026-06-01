class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m1(nums1.begin(), nums1.end());
        unordered_set<int> m2(nums2.begin(), nums2.end());
        vector<int> a1, a2;

        for(int n : m1){
            if(!(m2.count(n))) a1.push_back(n);
        }

        for(int n : m2){
            if(!(m1.count(n))) a2.push_back(n);
        }

        return {a1, a2};
    }
};