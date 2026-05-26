class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map <char, int> m;
        int cnt = 0;

        for(char c : word){
            m[c]++;
        }

        for(char c = 'a'; c <= 'z'; c++){
            if(m[c]>0 && m[toupper(c)]>0) cnt++;
        }

        return cnt;
    }
};