class Solution {
public:
int fibDP(int n , vector<int>&f ) {
    if(n <= 2) {
        return n ; 
    }
    if(f[n] != -1){
        return f[n] ; 
    }
    return   f[n] =  fibDP(n-1 , f) + fibDP(n-2 , f) ; 
}
    int climbStairs(int n) {

        //  if(n <= 2){
        //     return n;
        // }

        // int prev1 = 1;
        // int prev2 = 2;

        // for(int i = 3; i <= n; i++){
        //     int curr = prev1 + prev2;

        //     prev1 = prev2;
        //     prev2 = curr;
        // }

        // return prev2;
        
        vector<int> f(n+1 , -1) ; 
        return fibDP(n , f); 
    }
};