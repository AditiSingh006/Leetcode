class Solution {
public:
int gcd_(int a, int b){
    if(b==0) return a;
    return gcd_(b,a%b);
}
    int gcdOfOddEvenSums(int n) {
        int e_sum = n*(n+1);
        int o_sum = n*n;
        return gcd_(e_sum, o_sum);
    }
};