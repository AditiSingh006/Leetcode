class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();

        vector<int> mp1(256, -1);
        vector<int> mp2(256, -1);

        for (int i = 0; i < n; i++) {
            char a = s[i];
            char b = t[i];

            if (mp1[a] != mp2[b]) {
                return false;
            }

            mp1[a] = i;
            mp2[b] = i;
        }

        return true;
    }
};