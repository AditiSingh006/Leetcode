class LFUCache {
public:
    struct Node {
        int value;
        int freq;
        list<int>::iterator it;
    };

    int capacity;
    int minFreq;

    // key -> Node
    unordered_map<int, Node> mp;

    // frequency -> list of keys
    // front = most recently used
    // back  = least recently used
    unordered_map<int, list<int>> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {
        int freq = mp[key].freq;

        // Remove key from its old frequency list
        freqList[freq].erase(mp[key].it);

        // If this was the last key with minFreq,
        // increase minFreq
        if (freq == minFreq && freqList[freq].empty()) {
            minFreq++;
        }

        // Increase frequency
        mp[key].freq++;

        int newFreq = mp[key].freq;

        // Put key at front because it is now most recently used
        freqList[newFreq].push_front(key);

        // Save new iterator
        mp[key].it = freqList[newFreq].begin();
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        updateFreq(key);

        return mp[key].value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        // Key already exists
        if (mp.find(key) != mp.end()) {
            mp[key].value = value;

            // put() also counts as a use
            updateFreq(key);

            return;
        }

        // Cache is full
        if (mp.size() == capacity) {
            // Least frequent list
            list<int>& lst = freqList[minFreq];

            // Back = least recently used
            int lfuKey = lst.back();

            lst.pop_back();

            mp.erase(lfuKey);
        }

        // New key starts with frequency 1
        freqList[1].push_front(key);

        mp[key] = {value, 1, freqList[1].begin()};

        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */