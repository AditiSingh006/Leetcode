class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> bal;

        for(int i=0; i<text.length(); i++){
            bal[text[i]]++;
        }
        
        int m = min(bal['b'], bal['a']);
        int j = min(m, bal['l']/2);
        int k = min(j, bal['o']/2);
        int a = min(k, bal['n']);
        return a;
    }
};