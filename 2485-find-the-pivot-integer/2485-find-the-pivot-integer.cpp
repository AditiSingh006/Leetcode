class Solution {
public:
    int pivotInteger(int n) {
        int t_sum = n*(n+1)/2;
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum = sum + i;
            if(sum==(t_sum-sum+i)) return i;
        }
        return -1;
    }
};