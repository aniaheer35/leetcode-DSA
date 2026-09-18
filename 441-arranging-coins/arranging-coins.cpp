class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 0 ){
            return 0 ; 
        }
         long long ans = (-1 + sqrt(1 + 8LL * n)) / 2;
        return ans ;
    }
};