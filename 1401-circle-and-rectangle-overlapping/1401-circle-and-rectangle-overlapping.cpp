class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int cx = max(x1,min(x2,xCenter));
        int cy = max(y1,min(y2,yCenter));
        int diff = pow(cx-xCenter,2)+pow(cy-yCenter,2);
        if(diff > radius*radius)return false;

        return true;
    }
};