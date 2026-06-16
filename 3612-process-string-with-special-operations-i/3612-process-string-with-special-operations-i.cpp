class Solution {
public:

    string processStr(string s) {
        int n = s.length();
        string result = "";
        
        for(int i=0; i<n; i++){

            if(s[i]=='*'){
                if(!result.empty()) result.pop_back();
            }

            else if(s[i]=='#'){
                result = result + result;
            }

            else if(s[i]=='%'){
                reverse(result.begin(), result.end());;
            }

            else{
                result = result + s[i];
            }
        }
        return result;
    }
};