class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        vector<char> vow;

        for(char c : s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c =='U'){
                vow.push_back(c);
            }
        }

        int k = vow.size()-1;

        for(int i=0; i<n; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                s[i] = vow[k--];
            }
        }

        return s;

    }
};