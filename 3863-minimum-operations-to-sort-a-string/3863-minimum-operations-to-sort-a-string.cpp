class Solution {
public:
    int minOperations(string s) {
        string t = s;
        sort(t.begin(), t.end());

        if (s == t) return 0;

        int n = s.size();

        // Check if one operation is enough
        if (s[0] == t[0] || s[n - 1] == t[n - 1]) {
            return 1;
        }

        // Check special cases where two operations are enough
        if (count(s.begin(), s.end(), s[0]) > 1 ||
            count(s.begin(), s.end(), s[n - 1]) > 1) {
            return 2;
        }

        // If the string has length 2, sorting the entire string
        // is forbidden, so an unsorted string cannot be sorted.
        if (n == 2) return -1;

        // If the maximum character is at the beginning
        // and the minimum character is at the end,
        // three operations are needed.
        if (s[0] == t[n - 1] && s[n - 1] == t[0]) {
            return 3;
        }

        return 2;
    }
};