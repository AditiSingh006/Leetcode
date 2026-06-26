class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int ti = 0;
        for (int i = 1; i <= n && ti < target.size(); i++) {
            ops.push_back("Push");
            if (target[ti] != i)
                ops.push_back("Pop");
            else
                ti++;
        }
        return ops;
    }
};