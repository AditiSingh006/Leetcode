class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        int n = chars.size();

        for(int i=0; i<n; i++){
            s= s + (chars[i]);
            int count = 1;
            while((i!=n-1) && (chars[i]==chars[i+1])){
                count++;
                i++;
            }
            if(count>1){
                string k = to_string(count);
                for(char z : k) s = s + z;
            }
        }

        for(int j=0; j<s.length(); j++){
            chars[j] = s[j];
        }

        return s.length();
    }
};