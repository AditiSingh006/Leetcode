class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        int k = n;
        while(k%2==0) k = k / 2;
        while(k%3==0) k = k / 3;
        while(k%5==0) k = k / 5;
        return k==1;
    }
};