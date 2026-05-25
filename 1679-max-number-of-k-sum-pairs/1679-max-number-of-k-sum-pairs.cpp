class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int o = 0;
        unordered_map<int,int> mp;
        
        for(int n : nums){
            int need = k - n;
            if(mp[need]>0){
                o++;
                mp[need]--;
            }
            else mp[n]++;
        }

        return o;
    }
};