class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int maxn = 0;
        bool f = false;

        if(arr[0]!=1){
            for(int i=0; i<n; i++){
                if(arr[i]==1){
                    swap(arr[i],arr[0]);
                    f = true;
                    break;
                }
            }
        }

        if(!f) arr[0] = 1;

        for(int i=0; i<n-1; i++){
            if(abs(arr[i]-arr[i+1])>1){
                arr[i+1] = arr[i]+1;
            }
        }

        for(int i=0; i<n; i++){
            maxn = max(arr[i], maxn);
        }

        return maxn;

    }
};