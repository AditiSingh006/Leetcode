class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int max_a = INT_MIN;
        
        while(left<right){
            max_a = max(max_a, min(height[left], height[right])*(right-left));
            if(height[right]>height[left]) left++;
            else right--;
        }

        return max_a;
    }
};