class RandomizedSet {
public:
    vector<int> nums;

    // value -> index in nums
    unordered_map<int, int> mp;

    RandomizedSet() {
    }
    
    bool insert(int val) {
        // Already exists
        if (mp.find(val) != mp.end()) {
            return false;
        }

        // Add to vector
        nums.push_back(val);

        // Store its index
        mp[val] = nums.size() - 1;

        return true;
    }
    
    bool remove(int val) {
        // Doesn't exist
        if (mp.find(val) == mp.end()) {
            return false;
        }

        int index = mp[val];
        int last = nums.back();

        // Move last element to the position of val
        nums[index] = last;

        // Update last element's index
        mp[last] = index;

        // Remove last position
        nums.pop_back();

        // Remove val from map
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */