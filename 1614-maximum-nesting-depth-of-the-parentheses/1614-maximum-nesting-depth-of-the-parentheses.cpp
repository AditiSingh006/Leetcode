class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, depth = 0;

        for (char ch : s) {
            if (ch == '(') {
                depth++;
                ans = max(ans, depth);
            }
            else if (ch == ')') {
                depth--;
            }
        }

        return ans;
    }
};