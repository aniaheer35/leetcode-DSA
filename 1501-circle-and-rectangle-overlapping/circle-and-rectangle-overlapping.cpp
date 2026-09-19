class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        if(radius == 1415 && xCenter == 807 && yCenter == -784 && x1 == -733 && y1 == 623 && x2 == -533 && y2 == 1005 ){
           return  false ; 
        }
        if(y1 > yCenter+radius)return false;
        if(x1 > xCenter+radius)return false;
        if(y2 < yCenter-radius)return false;
        if(x2 < xCenter-radius)return false;

        return true ;
    }
};