class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        while(left<=right){
            int i = left;
            bool flag = true;
            while(i){
                int digit = i%10;
                if(digit==0 || left%digit){
                    flag = false;
                    break;
                }
                
                i = i / 10;
            }
            if(flag) ans.push_back(left);
            left++;
        }
        return ans;
    }
};