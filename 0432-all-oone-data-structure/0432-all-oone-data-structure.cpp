class AllOne {
public:
    struct Node {
        int count;
        unordered_set<string> keys;
    };

    // Buckets sorted by count
    list<Node> buckets;

    // key -> iterator pointing to its bucket
    unordered_map<string, list<Node>::iterator> mp;

    AllOne() {
    }
    
    void inc(string key) {
        // Key doesn't exist
        if (mp.find(key) == mp.end()) {
            
            // If count-1 bucket doesn't exist,
            // create count-1 bucket before the first bucket
            if (buckets.empty() || buckets.front().count != 1) {
                buckets.push_front({1, {}});
            }

            buckets.front().keys.insert(key);
            mp[key] = buckets.begin();

            return;
        }

        auto it = mp[key];
        int count = it->count;

        auto next = std::next(it);

        // Need count + 1 bucket
        if (next == buckets.end() || next->count != count + 1) {
            next = buckets.insert(next, {count + 1, {}});
        }

        // Move key to next bucket
        next->keys.insert(key);
        mp[key] = next;

        it->keys.erase(key);

        // Remove empty bucket
        if (it->keys.empty()) {
            buckets.erase(it);
        }
    }
    
    void dec(string key) {
        auto it = mp[key];
        int count = it->count;

        // Count becomes 0 → remove key completely
        if (count == 1) {
            it->keys.erase(key);
            mp.erase(key);

            if (it->keys.empty()) {
                buckets.erase(it);
            }

            return;
        }

        auto prev = (it == buckets.begin()) ? buckets.end() : std::prev(it);

        // Need count - 1 bucket
        if (it == buckets.begin() || prev->count != count - 1) {
            prev = buckets.insert(it, {count - 1, {}});
        }

        // Move key to previous bucket
        prev->keys.insert(key);
        mp[key] = prev;

        it->keys.erase(key);

        // Remove empty bucket
        if (it->keys.empty()) {
            buckets.erase(it);
        }
    }
    
    string getMaxKey() {
        if (buckets.empty()) {
            return "";
        }

        return *buckets.back().keys.begin();
    }
    
    string getMinKey() {
        if (buckets.empty()) {
            return "";
        }

        return *buckets.front().keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */