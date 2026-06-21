class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size(), c=0;
        sort(costs.begin(), costs.end());

        for(int i=0; i<n; i++){
            if(coins>=costs[i]){
                coins -= costs[i];
                c++;
            }
            else if(coins<=0) break;
        }
        
        return c;
    }
};