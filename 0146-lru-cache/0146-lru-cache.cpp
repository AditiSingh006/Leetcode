class LRUCache {
public:
    int capacity;

    // key -> {value, iterator pointing to its position in list}
    unordered_map<int, pair<int, list<int>::iterator>> mp;

    // Front = LRU, Back = MRU
    list<int> lru;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // Key doesn't exist
        if (mp.find(key) == mp.end())
            return -1;

        // Move this key to the back (MRU)
        lru.erase(mp[key].second);
        lru.push_back(key);

        // Update iterator
        mp[key].second = prev(lru.end());

        return mp[key].first;
    }

    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {

            // Remove old position
            lru.erase(mp[key].second);

            // Add key at back (MRU)
            lru.push_back(key);

            // Update value and iterator
            mp[key] = {value, prev(lru.end())};

            return;
        }

        // Key is new
        lru.push_back(key);
        mp[key] = {value, prev(lru.end())};

        // Capacity exceeded
        if (mp.size() > capacity) {
            int lruKey = lru.front();

            lru.pop_front();
            mp.erase(lruKey);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */