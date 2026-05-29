class Solution {
public:
int sum(int n){
    int k = 0;
    while(n){
        k = k + n%10;
        n = n / 10;
    }
    return k;
}

    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        
        for(int n : nums){
            mini = min(mini, sum(n));
        }

        return mini;
    }
};