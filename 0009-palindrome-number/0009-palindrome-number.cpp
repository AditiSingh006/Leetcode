class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long rev = 0, k = x;
        while(k){
            rev = rev*10 + (k%10);
            k = k / 10;
        }
        return (x==rev);
    }
};