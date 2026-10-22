class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int upper = 0;

        for (char c : word) {
            if (isupper(c)) {
                upper++;
            }
        }

        if (upper == n) return true;           // All uppercase
        if (upper == 0) return true;           // All lowercase
        if (upper == 1 && isupper(word[0])) return true; // First uppercase

        return false;
    }
};