class Solution {
public:
    bool canAliceWin(int n) {
        int count = 10 ; 
        int p = 0  ;
        while(n > 0){
            if(n >= count){
                n = n-count ; 
                count-- ; 
                p++ ; 
            }
            else {
                break ; 
            }
        }
        if(p%2 == 1){
            return true ; 
        }
        return false ;
    }
};