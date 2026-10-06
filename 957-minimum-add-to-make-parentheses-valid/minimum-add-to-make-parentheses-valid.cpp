class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size() ; 
        int A = 0 ; 
        int move = 0 ; 
        for(int i = 0 ; i < n ; i++ ){https://leetcode.com/u/Anil7849$0
            if(s[i] == '(') {
              A++ ; 
            }
            else {
                if(A > 0 ) {
                    A-- ; 
                }
                else {
                    move++ ; 
                }
            }
         
        }
           return move + A ;
    }
};