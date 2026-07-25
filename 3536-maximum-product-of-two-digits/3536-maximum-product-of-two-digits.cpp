class Solution {
public:
    int maxProduct(int n) {
        int k = n;
        int m1 = -1, m2 = -1;
        while(k){
            int d = k % 10;
            if(d>m1){
                m2 = m1;
                m1 = d;
            }
            else if(d>m2) m2 = d;
            k = k / 10;
        }
        return m1*m2;
    }
};