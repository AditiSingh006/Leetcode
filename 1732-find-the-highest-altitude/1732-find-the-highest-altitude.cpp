class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int k = 0;
        int maxc = 0;
        for(int i=0; i<gain.size(); i++){
            k = k + gain[i];
            maxc = max(k, maxc);
        }
        return maxc;
    }
};