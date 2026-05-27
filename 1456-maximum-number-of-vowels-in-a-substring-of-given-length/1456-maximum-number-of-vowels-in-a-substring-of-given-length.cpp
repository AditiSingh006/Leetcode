class Solution {
public:

    bool isv(char c){
        if((c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u')) return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int count = 0;
        int maxC = 0;

        for(int i = 0; i<k; i++){
            if(isv(s[i])) count++;
        }

        maxC = max(count, maxC);
        
        for(int i = k; i < n; i++){
            if(isv(s[i])) count++;
            if(isv(s[i-k])) count--;
            maxC = max(count, maxC);
        }

        return maxC;
    }
};