class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = "";
        int count = 0;

        // Repeat a until s is at least as long as b
        while (s.length() < b.length()) {
            s += a;
            count++;
        }

        // Check if b is a substring
        if (s.find(b) != string::npos) {
            return count;
        }

        // One extra repetition may be enough
        s += a;
        count++;

        if (s.find(b) != string::npos) {
            return count;
        }

        return -1;
    }
};