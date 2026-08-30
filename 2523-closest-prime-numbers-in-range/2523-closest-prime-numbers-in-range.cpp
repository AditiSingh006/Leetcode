class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right+1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i<=right/i; i++){
            if(isPrime[i]){
                for(int j = i*i; j<=right; j = j+i){
                    isPrime[j] = false;
                }
            }
        }

        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(isPrime[i]){
                ans.push_back(i);
            }
        }

        int mini = INT_MAX;
        for(int i=1; i<ans.size(); i++){
            mini = min(mini, ans[i]-ans[i-1]);
        }

        for(int i=1; i<ans.size(); i++){
            if(ans[i]-ans[i-1]==mini) return {ans[i-1], ans[i]};
        }

        return {-1,-1};
    }
};