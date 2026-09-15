class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map <int,int> mp;
        for(int i:arr){
            mp[i]++;
        }
        set<int> occurrences;
        for (auto& pair : mp) {
            if (occurrences.find(pair.second) != occurrences.end()){
                return false;
            }
            occurrences.insert(pair.second);
        }
        return true;
    }
};