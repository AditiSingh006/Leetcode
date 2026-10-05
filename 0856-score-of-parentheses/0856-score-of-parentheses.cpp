class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int c = 0, ans = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') c++;
            else{
                c--;
                if (s[i - 1] == '(') {
                ans += (1 << c);
            }
            }
        }
        return ans;
    }
};