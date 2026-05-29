class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        int i = 0, j = 0, c = 0;

        string ans;

        while(i<l1 && j<l2){
            if(c%2==0){
                ans = ans + word1[i];
                c++, i++;
            }
            else{
                ans = ans + word2[j];
                c++, j++;
            }
        }

        while(i<l1){
            ans = ans + word1[i];
            i++;
        }

        while(j<l2){
            ans = ans + word2[j];
            j++;
        }

        return ans;

    }
};