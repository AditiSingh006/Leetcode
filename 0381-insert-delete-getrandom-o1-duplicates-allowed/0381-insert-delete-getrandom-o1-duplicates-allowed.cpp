class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;

    RandomizedCollection() {
    }
    
    bool insert(int val) {
        bool first = mp[val].empty();

        nums.push_back(val);
        mp[val].insert(nums.size() - 1);

        return first;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end() || mp[val].empty()) {
            return false;
        }

        // Get any index of val
        int index = *mp[val].begin();

        // Last element
        int lastIndex = nums.size() - 1;
        int lastVal = nums[lastIndex];

        // Remove the selected occurrence
        mp[val].erase(index);

        // If index is not the last position,
        // move last element here
        if (index != lastIndex) {
            nums[index] = lastVal;

            mp[lastVal].erase(lastIndex);
            mp[lastVal].insert(index);
        }

        nums.pop_back();

        if (mp[val].empty()) {
            mp.erase(val);
        }

        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */