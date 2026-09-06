class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int R1 = (ax2-ax1) * (ay2-ay1);
        int R2 = (bx2-bx1) * (by2-by1);

        int over = 0;
        int l = min(bx2,ax2) - max(bx1,ax1);
        int w = min(by2,ay2) - max(ay1,by1);

        if(l>0 && w>0){
            over = l * w;
        }

        return (R1 + R2 - over);
    }
};