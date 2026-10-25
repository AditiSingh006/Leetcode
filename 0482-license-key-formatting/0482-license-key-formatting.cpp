class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int count = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') {
                continue;
            }

            ans += toupper(s[i]);
            count++;

            if (count == k) {
                ans += '-';
                count = 0;
            }
        }

        reverse(ans.begin(), ans.end());

        if (!ans.empty() && ans[0] == '-') {
            ans.erase(ans.begin());
        }

        return ans;
    }
};