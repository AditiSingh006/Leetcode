class Solution {
public:
    int reverseBits(int n) {
        int k = 0;
        for(int i=0; i<32; i++){
            k = k << 1;
            k = k | (n&1);
            n = n >> 1;
        }
        return k;
    }
};